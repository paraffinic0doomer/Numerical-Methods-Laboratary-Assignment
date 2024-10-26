# Numerical Methods Laboratory Assignment
Welcome to the Numerical Methods Console Application. This is presented by Group 21 consisting of Roll 2107009, 2107026, and 2107095. This is a very user-friendly console application for solving various numerical problems.

## Features:
Linear Equation
Non Linear Equation
Differential Equation
Matrix Inversion

### Linear Equation:
Linear Equations: Offers options like Jacobi and Gauss-Seidel iterative methods, Gauss Elimination, and Jordan Elimination. Nonlinear Equations: Runs a nonlinear equation solver. Differential Equations: The solution of differential equations using the Runge-Kutta method is implemented here. Inverse of Matrix: It performs matrix inversion. Each option will trigger a different function stored in a different file, which allows modularity and maintainability. Depending on the user's choice, a call to the respective function will be issued; in case of an invalid option chosen, an error message will appear. Now this program is a very versatile tool for immediate access to the core numerical methods for users.

### The brief explanation of each method is given below:

#### Gauss-Seidel iterative method:
The following C++ code solves a system of linear equations by using the Gauss-Seidel method. It first asks the user to enter the number of variables and the coefficients of the equations, then builds up an augmented matrix representing the system. The first thing this function does is check for diagonal dominance, a sufficient condition for convergence in the Gauss-Seidel method. This function calculates the magnitude of the diagonal coefficient for each equation and then compares that with the sum of magnitudes of the other coefficients in that same row. It checks every diagonal element against the sum of the other elements in its row; if any of those diagonal elements are found smaller than the sum, the matrix is not diagonally dominant, and a message appears while the function is terminated.

If the matrix is diagonally dominant, the function initializes a solution vector filled with zeroes and begins an iterative process, running up to 100 iterations, or until convergence, where successive estimates differ by less than the specified tolerance of 1×10^(-6). During each iteration, it updates the current estimate of the value for each variable from the latest estimates of the other variables. Finally, the function prints the calculated solutions for each variable, formatting the output to show zeros in the correct positions. The function returns true on successful execution of solving the equations.

On the whole, this example code illustrates the Gauss-Seidel method rather well and considers the fact that the key to convergence is diagonal dominance. This example shows an iterative solution process in a very clear fashion. It is convenient for users who want to solve linear equations in a systematic manner, with considerations of the iterative nature of this method.

#### Jacobi Iterative method:
Following is the C++ code to use the Jacobi method in solving systems of linear equations. The code starts with requiring the user to input the number of variables and coefficients of each equation to form an augmented matrix of the system. Input and Matrix Construction. It will then prompt the user to enter coefficients of variables and the constant term for each equation. Coefficients are put in a 2D vector, arr, for which the rows correspond to the equations. Diagonal Dominance Check. This function checks if the matrix is diagonally dominant or not. This is a necessary criterion for convergence in the Jacobi method. It calculates, for every row, the absolute value of the diagonal coefficient and the sum of the absolute values of the other coefficients in the row. If it finds a diagonal element that's less than the sum of the other elements in the row, it sets a flag to indicate that the matrix is not diagonally dominant. If this condition fails it displays an error message and exits the function. Computación Iterativa. If the matrix is diagonally dominant, it initializes two vectors, x1 and x1_new, to store the current and newly computed values of the variables respectively. It sets up a tolerance level of 1×10^(-6) and a maximum iteration count of 100. The central loop iterates up to 100 times. At each iteration, it calculates the new estimate of every variable based on previous estimates of the current iteration. Thereafter, it checks for the error—the sum of the absolute deviation between new and old values—being less than the tolerance level to break the loop.

Output. Finally, the function prints the calculated solutions of each variable, considering any -0 as 0 for better readability. The function returns true on completion, elaborating the step-by-step procedure for solving linear equations.

#### Gaussian Elimination:
The code for the Gaussian elimination method is for solving a system of linear equations. Following are its elements and how they work:

Functions description: print_gauss: It prints the augmented matrix with six decimal places precision. It uses setw(10) for column alignment in the output. It changes any -0 to 0.000000 for readability. Gaussian_function: Performs the Gaussian elimination algorithm. For every column (pivot), the entries of the row that are below the pivot, are eliminated by zeroing it. For each such element to be zeroed it finds the most "near" nonzero element above it and performs the row operations. Then, after every row operation, the current state of the matrix is printed via print_gauss. Gauss_Eliminations: Entry of Gaussian elimination. The program will prompt the user for the number of unknowns and coefficients of the equations to build an augmented matrix. Calling print_gauss will do the elimination. It then prints the modified matrix after Gaussian elimination. Input/Output Flow. The program asks the user to input the number of the unknowns and coefficients of the equation. The program will build an augmented matrix based on the input to be given by the user. It shows the original matrix and the final form after elimination, step by step.

#### Gauss-Jordan Elimination:
Following is a C++ code to solve a system of linear equations using the Gauss-Jordan elimination technique. It effectively changes an augmented matrix through a series of operations that puts it in a form where it gives the solutions of the equations.

Function description:

Matrix Printing Function (print): It prints the matrix to six decimal places precision, making sure the formatting is appropriate with the use of setw. It also checks for -0 and prints it out as 0.000000.

Gaussian Elimination (gauss_elemination): It converts the matrix to upper triangular form. The function will then loop through each column and try to eliminate all values below the pivot using row operations, searching for a non-zero above the current pivot and updating accordingly, printing the states of a matrix after every iteration.

Jordan Elimination: Further refines the matrix to the reduced row echelon form by processing columns from right to left. It targets every non-zero element in its column to eliminate values above the element to attain a simplified structure.

Row Echelon Form (row_echalon): Turns pivot elements to one by dividing each row by its corresponding pivot; this sets up an identity matrix structure.

Pivot Checking (is_pivot_zero): Checks if any pivot element is zero and swaps it with a nonzero row below. The step is essential in order to avoid division by zero during the elimination.

#### LU decomposition method:
The following C++ code performs LU decomposition for solving a system of linear equations. It basically factorizes a matrix into a lower triangular matrix L and an upper triangular matrix U, hence enhancing efficiency in the solution process.

Function description:

LU_solve Function: This function takes one argument, which is matrix size, an augmented matrix, and a solution vector.

It declares matrices L and U and initializes them. LU Decomposition: It fills U from the input and then modifies it with previously computed elements of L and U. It computes the elements of L, normalized with the diagonal of U. Forward Substitution: It calculates the vector y from Ly=b, where b corresponds to the last column of the augmented matrix.

Back Substitution: Finally, it calculates the solution vector x from Ux=y. LU_Decomposition Function: The logic of this function is to take user input for the augmented matrix. It first asks the user to enter the number of variables and then the coefficients. Once the inputs are read, the program calls the function LU_solve to carry out the actual computation.

#### Matrix Inversion:
The following C++ program calculates the inverse of a matrix by Gaussian and Jordan elimination methods, operating with an augmented matrix, which is a combination of the source matrix and an identity matrix.

Function Description:

Print Function: The following print function will print the augmented matrix with proper alignment by using 'setw' to make a pretty column formatting, having up to six decimal places of precision.

Gaussian Elimination: The gauss_elemination function clears entries below each pivot in order to achieve an upper triangular matrix. It runs through rows to clear entries below the pivot to zero.

Jordan Elimination: The function jordan_elemination takes the augmented matrix and further reduces the matrix so all terms above each pivot are zero. This is referred to as reduced row echelon.

Row Echelon Method: The function row_echalon simply scales the rows so that the pivot elements are equal to one. That is, the function takes the pivot number of each row and divides by it.

Inverse Matrix Function: This function will ask the user for the size of the matrix and its elements, build the augmented matrix, and then apply the elimination methods one by one. At the end, it extracts the inverse matrix from the augmented matrix and displays it.

### Non Linear Equation:
Polynomial Class
Properties:
degree: Representing the degree of the polynomial.
coefficients: A vector to hold the coefficients of the polynomial.
roots: A set that holds unique roots - no duplicate roots are counted.

Methods:
- Input Polynomial: This method inputs coefficients, including leading zeros. It will store them in a vector, and calculate the degree of the polynomial based on the highest non-zero coefficient.

- Display Polynomial: Displays the polynomial in standard form, accounting for the sign and positioning of terms.

- Evaluate Polynomial: Computes the polynomial value for a given x. This method iterates through all coefficients and calculates the resulting value, returning the total sum.

- Derivative: Computes the derivative of the polynomial, returning a new polynomial object. The derivative is computed as a polynomial of one degree lower, using the power rule of differentiation.

- Newton-Raphson Method: This is a central part of the implementation. It computes the roots of the polynomial using an iterative method. It takes an initial guess, checks convergence, and iteratively applies the Newton-Raphson formula until it finds an approximate root.

### Differential Equations:
Runge-Kutta Method
The implementation of the Runge-Kutta method in this C++ program allows the user to solve first-order ordinary differential equations (ODEs). 

Key Elements of Implementation:
1. Function Signature: The `rungeKutta` function does not take any parameters. Instead, it utilizes global constants for the initial conditions, function to evaluate, and the number of steps. It initializes time variables and computes values iteratively.

2. Initialization: Variables such as the initial value of `t` and `y`, the step size, and the total number of steps are defined. A vector is used to store the results at each step.

3. Iterative Computation: In a loop, the Runge-Kutta method calculates the next value of `y` based on the current value, applying the RK4 formula, which incorporates the slope at various points within the interval to estimate the next value. 

4. Output: The results are printed in a readable format, showing the values of `t` and `y` at each step.

### Conclusion:
This numerical methods laboratory assignment provides a user-friendly interface to perform various numerical methods like linear equations, non-linear equations, differential equations, and matrix inversions. Users can select the method of interest, and the program handles the rest with detailed outputs.
