#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <set>

class Polynomial {
private:
    int degree;
    std::vector<double> coefficients;

public:
    std::set<double> roots; // Set to store unique roots

    Polynomial(int deg) : degree(deg), coefficients(deg + 1) {}

    void setCoefficients() {
        std::cout << "Enter coefficients from highest degree to constant term:\n";
        for (int i = 0; i <= degree; ++i) {
            std::cout << "Coefficient for x^" << (degree - i) << ": ";
            std::cin >> coefficients[i];
        }
    }

    double evaluate(double x) const {
        double result = 0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * std::pow(x, degree - i);
        }
        return result;
    }

    double evaluateDerivative(double x) const {
        double result = 0;
        for (int i = 0; i < degree; ++i) {
            result += coefficients[i] * (degree - i) * std::pow(x, degree - i - 1);
        }
        return result;
    }

    void printRoots() const {
        if (roots.empty()) {
            std::cout << "No roots found.\n";
        } else {
            std::cout << "Roots are [ ";
            for (const double root : roots) {
                std::cout << root << " ";
            }
            std::cout << "]\n";
        }
    }
};

class RootFinder {
protected:
    Polynomial& polynomial;
    double tolerance = 1e-6;
    std::vector<std::pair<double, double>> intervals;

public:
    RootFinder(Polynomial& poly) : polynomial(poly) {}

    void setIntervals() {
        int numIntervals;
        std::cout << "Enter the number of intervals: ";
        std::cin >> numIntervals;

        for (int i = 0; i < numIntervals; ++i) {
            double a, b;
            std::cout << "Interval " << i + 1 << " (enter as two space-separated values a and b):\n";
            std::cin >> a >> b;
            intervals.push_back({a, b});
        }
    }

    virtual void findRoots() = 0;  // Pure virtual function for finding roots
};

class BisectionMethod : public RootFinder {
public:
    using RootFinder::RootFinder;

    void findRoots() override {
        for (const auto& interval : intervals) {
            double a = interval.first;
            double b = interval.second;
            double step = (b - a) / 100;

            for (double x = a; x < b; x += step) {
                double f_x = polynomial.evaluate(x);
                double f_next = polynomial.evaluate(x + step);

                if (f_x * f_next < 0) {
                    double root = findRootInInterval(x, x + step);
                    polynomial.roots.insert(root);
                }
            }
        }
    }

private:
    double findRootInInterval(double a, double b) {
        while ((b - a) >= tolerance) {
            double mid = (a + b) / 2.0;
            double f_a = polynomial.evaluate(a);
            double f_mid = polynomial.evaluate(mid);

            if (fabs(f_mid) < tolerance) return mid;

            if (f_a * f_mid < 0) b = mid;
            else a = mid;
        }
        return (a + b) / 2.0;
    }
};

class FalsePositionMethod : public RootFinder {
public:
    using RootFinder::RootFinder;

    void findRoots() override {
        for (const auto& interval : intervals) {
            double a = interval.first;
            double b = interval.second;
            double step = (b - a) / 100;

            for (double x = a; x < b; x += step) {
                double f_x = polynomial.evaluate(x);
                double f_next = polynomial.evaluate(x + step);

                if (f_x * f_next < 0) {
                    double root = findRootInInterval(x, x + step);
                    polynomial.roots.insert(root);
                }
            }
        }
    }

private:
    double findRootInInterval(double a, double b) {
        double fa = polynomial.evaluate(a);
        double fb = polynomial.evaluate(b);
        while (fabs(b - a) >= tolerance) {
            double root = (a * fb - b * fa) / (fb - fa);
            double f_root = polynomial.evaluate(root);
            if (fabs(f_root) < tolerance) return root;

            if (fa * f_root < 0) { b = root; fb = f_root; }
            else { a = root; fa = f_root; }
        }
        return (a * fb - b * fa) / (fb - fa);
    }
};

class SecantMethod : public RootFinder {
public:
    using RootFinder::RootFinder;

    void findRoots() override {
        for (const auto& interval : intervals) {
            double a = interval.first;
            double b = interval.second;
            double step = (b - a) / 100;

            for (double x = a; x < b; x += step) {
                double f_x = polynomial.evaluate(x);
                double f_next = polynomial.evaluate(x + step);

                if (f_x * f_next < 0) {
                    double root = findRootInInterval(x, x + step);
                    polynomial.roots.insert(root);
                }
            }
        }
    }

private:
    double findRootInInterval(double a, double b) {
        double fa = polynomial.evaluate(a);
        double fb = polynomial.evaluate(b);
        while (fabs(b - a) >= tolerance) {
            double root = b - fb * (b - a) / (fb - fa);
            double f_root = polynomial.evaluate(root);
            if (fabs(f_root) < tolerance) return root;

            a = b; fa = fb;
            b = root; fb = f_root;
        }
        return b - fb * (b - a) / (fb - fa);
    }
};

class NewtonRaphsonMethod : public RootFinder {
public:
    using RootFinder::RootFinder;

    void findRoots() override {
        for (const auto& interval : intervals) {
            double a = interval.first;
            double b = interval.second;
            double step = (b - a) / 100;

            for (double x = a; x < b; x += step) {
                double root = findRootInInterval(x);
                polynomial.roots.insert(roundToTolerance(root));
            }
        }
    }

private:
    double findRootInInterval(double initialGuess) {
        double x = initialGuess;
        for (int i = 0; i < 1000; ++i) {
            double fx = polynomial.evaluate(x);
            double fx_derivative = polynomial.evaluateDerivative(x);
            if (fabs(fx_derivative) < tolerance) break;

            double x_next = x - fx / fx_derivative;
            if (fabs(x_next - x) < tolerance) return x_next;
            x = x_next;
        }
        return x;
    }

    // Rounds a value to the tolerance level to avoid near-duplicate roots
    double roundToTolerance(double value) const {
        return std::round(value / tolerance) * tolerance;
    }
};

void non_linear() {
    int degree;
    std::cout << "Enter the degree of the polynomial: ";
    std::cin >> degree;

    Polynomial polynomial(degree);
    polynomial.setCoefficients();

    int method_choice;
    std::cout << "\nChoose a root-finding method:\n";
    std::cout << "1. Bisection Method\n";
    std::cout << "2. False Position Method\n";
    std::cout << "3. Secant Method\n";
    std::cout << "4. Newton-Raphson Method\n";
    std::cin >> method_choice;

    RootFinder* method;
    switch (method_choice) {
        case 1:
            method = new BisectionMethod(polynomial);
            break;
        case 2:
            method = new FalsePositionMethod(polynomial);
            break;
        case 3:
            method = new SecantMethod(polynomial);
            break;
        case 4:
            method = new NewtonRaphsonMethod(polynomial);
            break;
        default:
            std::cout << "Invalid choice\n";
            return ;
    }

    method->setIntervals();
    method->findRoots();

    polynomial.printRoots(); // Print all unique roots

    delete method;
    return ;
}
