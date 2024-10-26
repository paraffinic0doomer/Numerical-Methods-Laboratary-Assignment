#include <iostream>
#include <iomanip>

using namespace std;

double x0 = 0.0; 
double y0 = 0.0; 
double x = 2.0;  
double h = 0.1;  
int choice;      
void inputSelection();
double f1(double x, double y) {
    return x + y; 
}

double f2(double x, double y) {
    return 2 * x; 
}

double f3(double x, double y) {
    return 3 - y; 
}

double f4(double x, double y) {
    return -y; 
}

double rungeKutta() {
    inputSelection();
    int n = static_cast<int>((x - x0) / h); 
    double k1, k2, k3, k4; 
    double y = y0; 

    for (int i = 0; i < n; i++) {
        switch (choice) {
            case 1:
                k1 = h * f1(x0, y);
                k2 = h * f1(x0 + h / 2, y + k1 / 2);
                k3 = h * f1(x0 + h / 2, y + k2 / 2);
                k4 = h * f1(x0 + h, y + k3);
                break;
            case 2:
                k1 = h * f2(x0, y);
                k2 = h * f2(x0 + h / 2, y + k1 / 2);
                k3 = h * f2(x0 + h / 2, y + k2 / 2);
                k4 = h * f2(x0 + h, y + k3);
                break;
            case 3:
                k1 = h * f3(x0, y);
                k2 = h * f3(x0 + h / 2, y + k1 / 2);
                k3 = h * f3(x0 + h / 2, y + k2 / 2);
                k4 = h * f3(x0 + h, y + k3);
                break;
            case 4:
                k1 = h * f4(x0, y);
                k2 = h * f4(x0 + h / 2, y + k1 / 2);
                k3 = h * f4(x0 + h / 2, y + k2 / 2);
                k4 = h * f4(x0 + h, y + k3);
                break;
            default:
                cout << "Invalid choice!\n";
                return 0; 
        }

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6; 
        x0 += h; 
    }

    cout<<"result: "<<y<<endl;
}

void inputSelection() {
    cout << "Select a problem to solve:\n";
    cout << "1. dy/dx = x + y (Initial y(0) = 1)\n";
    cout << "2. dy/dx = 2x (Initial y(0) = 0)\n";
    cout << "3. dy/dx = 3 - y (Initial y(0) = 0)\n";
    cout << "4. dy/dx = -y (Initial y(0) = 1)\n";
    cout << "Enter your choice (1-4): ";
    
    cin >> choice; 

    switch (choice) {
        case 1:
            y0 = 1.0; 
            break;
        case 2:
            y0 = 0.0; 
            break;
        case 3:
            y0 = 0.0; 
            break;
        case 4:
            y0 = 1.0; 
            break;
        default:
            cout << "Invalid choice!\n"; 
            exit(1); 
    }
}





