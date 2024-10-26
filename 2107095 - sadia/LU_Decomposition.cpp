#include <bits/stdc++.h>
using namespace std;

// Function to perform LU decomposition and solve the system of equations
void LU_solve(int n, vector<vector<float>>& matrix, vector<float>& solution) {
    // Initialize L and U matrices
    vector<vector<float>> L(n, vector<float>(n, 0));
    vector<vector<float>> U(n, vector<float>(n, 0));

    // LU decomposition process
    for (int i = 0; i < n; i++) {
        
        for (int j = i; j < n; j++) {
            U[i][j] = matrix[i][j];
            for (int k = 0; k < i; k++) {
                U[i][j] -= (L[i][k] * U[k][j]); // Adjust U using previously computed L and U
            }
        }

        L[i][i] = 1; // Set diagonal of L to 1

        // Calculate elements of L
        for (int j = i + 1; j < n; j++) {
            L[j][i] = matrix[j][i];
            for (int k = 0; k < i; k++) {
                L[j][i] -= (L[j][k] * U[k][i]); // Adjust L using previously computed L and U
            }
            L[j][i] /= U[i][i]; // Normalize L
        }
    }

    // Forward substitution to solve Ly = b
    vector<float> y(n);
    for (int i = 0; i < n; i++) {
        y[i] = matrix[i][n]; 
        for (int j = 0; j < i; j++) {
            y[i] -= (L[i][j] * y[j]); // Adjust y using L
        }
    }

    // Back substitution to solve Ux = y
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            solution[i] -= (U[i][j] * solution[j]); // Adjust solution using U
        }
        solution[i] /= U[i][i]; // Normalize solution
    }

    // Output the upper triangular matrix U
    cout << "The upper triangular matrix U is:" << endl;
    cout << fixed << setprecision(6) << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n + 1); j++) {
            if (U[i][j] == -0) {
                cout << setw(10) << 0.000000 << " "; 
            } else {
                cout << setw(10) << U[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;

    // Output the lower triangular matrix L
    cout << "The lower triangular matrix L is:" << endl;
    cout << fixed << setprecision(6) << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n + 1); j++) {
            if (L[i][j] == -0) {
                cout << setw(10) << 0.000000 << " "; 
            } else {
                cout << setw(10) << L[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Function to read the augmented matrix and initiate the LU decomposition
void LU_Decomposition() {
    int n;
    cout << "Enter the number of unknowns: ";
    cin >> n;

    vector<vector<float>> augmented(n, vector<float>(n + 1)); // Augmented matrix
    cout << "Enter the augmented matrix (coefficients and constants):\n";
    for (int i = 0; i < n; i++) {
        char o = 'a';
        for (int j = 0; j < n + 1; j++) {
            cout << "Value of " << o << i << ":" << endl; 
            cin >> augmented[i][j];
            o++;
        }
    }

    vector<float> solution(n); // Solution vector
    LU_solve(n, augmented, solution); // Call LU_solve

    // Output the solution vector
    cout << "Solution vector x:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}

   
    
