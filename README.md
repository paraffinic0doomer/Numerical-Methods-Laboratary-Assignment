# Numerical Methods Console Application

**Presented by Group 21**  
**Roll numbers:** 2107009, 2107026, 2107095

This is a very user-friendly console application for solving various numerical problems.

## Features:
1. Linear Equation
2. Non-Linear Equation
3. Differential Equation
4. Matrix Inversion

Each option triggers a different function stored in a different file, providing modularity and maintainability. Depending on the user's choice, a call to the respective function is issued. In case of an invalid option, an error message will appear. This program is a versatile tool for immediate access to core numerical methods.

---

### 1. Linear Equations

Linear Equations offers options like Jacobi and Gauss-Seidel iterative methods, Gauss Elimination, and Jordan Elimination.

#### Gauss-Seidel Iterative Method:
The following C++ code solves a system of linear equations using the Gauss-Seidel method. It first asks the user to enter the number of variables and the coefficients of the equations, then builds an augmented matrix representing the system.

- The first step checks for diagonal dominance, a sufficient condition for convergence in the Gauss-Seidel method. If the matrix is not diagonally dominant, a message will appear, and the function will terminate.
- If the matrix is diagonally dominant, the function initializes a solution vector filled with zeros and begins an iterative process, running up to 100 iterations or until convergence, where successive estimates differ by less than the specified tolerance of 1×10⁻⁶.
- The function updates the current estimate of each variable from the latest estimates of other variables during each iteration.
- Finally, it prints the calculated solutions for each variable and returns true on successful execution.

This example illustrates the Gauss-Seidel method, considering that diagonal dominance is key to convergence.

#### Jacobi Iterative Method:
This C++ code solves systems of linear equations using the Jacobi method.

- The code starts by asking the user to input the number of variables and coefficients for each equation to form an augmented matrix.
- It checks for diagonal dominance, a necessary condition for convergence in the Jacobi method. If the matrix is not diagonally dominant, the function exits with an error message.
- If the matrix is diagonally dominant, the program initializes vectors to store current and newly computed values of the variables.
- It runs a loop that iterates up to 100 times, checking if the error is less than the tolerance level of 1×10⁻⁶.
- Finally, the function prints the calculated solutions and returns true on completion.

#### Gaussian Elimination:
The Gaussian elimination method solves systems of linear equations.

- It performs Gaussian elimination by zeroing out elements below the pivot in each column using row operations.
- The program prints the matrix after every row operation.
- The user is prompted to input the number of unknowns and coefficients to build an augmented matrix, and the modified matrix is printed after Gaussian elimination.

#### Gauss-Jordan Elimination:
This C++ code solves systems of linear equations using the Gauss-Jordan elimination method.

- It prints the matrix with proper formatting and precision.
- The function performs Gaussian elimination, followed by Jordan elimination, to refine the matrix to its reduced row echelon form.
- Row operations are performed to eliminate values above pivots, and pivot elements are turned into ones by scaling rows.
- The matrix is printed step by step as the elimination process progresses.

#### LU Decomposition Method:
This C++ code performs LU decomposition to solve a system of linear equations.

- The function factorizes a matrix into a lower triangular matrix (L) and an upper triangular matrix (U).
- It uses forward and backward substitution to solve for the solution vector.

---

### 2. Non-Linear Equations

#### Non-Linear Equation Methods:
This section solves nonlinear equations, which include various root-finding methods such as Bisection, Newton-Raphson, Secant, and False Position.

#### Polynomial Class:
- **Properties**:
  - `degree`: Represents the degree of the polynomial.
  - `coefficients`: Holds the coefficients of the polynomial.
  - `roots`: A set that holds unique roots.
  
- **Methods**:
  - `setCoefficients()`: Asks the user for coefficients from the highest order term down to the constant term.
  - `evaluate(double x)`: Returns the value of the polynomial at x.
  - `evaluateDerivative(double x)`: Returns the value of the derivative of the polynomial at x.
  - `printRoots()`: Prints all unique roots found within given intervals.

#### Abstract Base Class RootFinder:
- **Purpose**: Defines a general structure for all root-finding methods.
  
- **Properties**:
  - `polynomial`: Pointer to the polynomial instance.
  - `tolerance`: Convergence tolerance predefined as 1e-6.
  - `intervals`: User-defined intervals where the search for the root will be made.
  
- **Methods**:
  - `setIntervals()`: Asks the user to define intervals for root searching.
  - `findRoots()`: A pure virtual function that must be implemented by specific root-finding methods.

#### Root-Finding Methods:
Each derived class implements one root-finding method:

- **Bisection Method**: Divides the interval repeatedly to find the root based on sign changes.

  - The bisection method works by finding a subinterval in which the root must lie (the function changes signs over this subinterval).
  - It does this by evaluating the function at the midpoint of the current interval. If the function has opposite signs at the two ends of the interval, the root lies between them, and the interval is halved.
  - This process continues until the interval is sufficiently small (determined by a predefined tolerance level).
  - This method is reliable but converges slowly compared to other methods.

- **False Position (Regula Falsi) Method**: Estimates the root by drawing a secant line between interval ends.

  - This method works similarly to the bisection method, but instead of dividing the interval in half, it uses the function values at the interval's endpoints to estimate the position of the root.
  - The intersection of the secant line with the x-axis gives an improved estimate of the root.
  - The method continues to update the interval by choosing the subinterval where the root lies, based on sign changes.

- **Secant Method**: Uses two initial guesses and iterates by calculating the x-intercept of the line joining them.

  - The secant method is an improvement over the bisection and false position methods in terms of speed but requires better initial guesses.
  - It works by taking two initial approximations to the root and iterating using the secant line between these two points to find a new approximation.
  - It is faster but less robust, especially if the initial guesses are far from the actual root.

- **Newton-Raphson Method**: Uses both the polynomial and its derivative to converge on a root.

  - The Newton-Raphson method uses the function's derivative to converge quickly on the root, making it one of the fastest methods.
  - Starting from an initial guess, it iteratively refines the guess by using the tangent line at the current guess to approximate the root.
  - The formula for updating the guess is:  
   x(n+1) = x(n) - f(x(n)) / f'(x(n))
  - This method converges rapidly when the initial guess is close to the actual root, but it requires the function's derivative, which can be difficult to compute for some functions. It may also fail to converge if the function behaves poorly at the initial guess.

---

### 3. Differential Equations

#### Runge-Kutta Method:
The program solves ordinary differential equations using the 4th order Runge-Kutta method.

- The user selects a differential equation and provides initial conditions.
- It handles several equations, such as:
  - `dy/dx = x + y` with `y(0) = 1`
  - `dy/dx = 2x` with `y(0) = 0`
  - `dy/dx = 3 - y` with `y(0) = 0`
  - `dy/dx = -y` with `y(0) = 1`
  
- After selecting an equation, the program computes the solution for y at a specified value of x using step size `h`.

---

### 4. Matrix Inversion

#### Matrix Inversion using Gaussian and Jordan Elimination:
This C++ program calculates the inverse of a matrix.

- The program asks for the size of the matrix and its elements to build an augmented matrix.
- It applies Gaussian and Jordan elimination to reduce the matrix to row echelon form and extracts the inverse matrix.
- The program prints the inverse matrix with proper formatting and precision.

---

## How to Use:

1. Choose an option from the main menu (Linear Equations, Non-Linear Equations, Differential Equations, or Matrix Inversion).
2. Follow the prompts to input the required data (such as coefficients or initial values).
3. The program will compute and display the results step by step.

This console application is a powerful tool for solving numerical problems, ideal for students and professionals working with numerical methods.
