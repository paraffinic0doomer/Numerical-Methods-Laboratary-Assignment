#pragma once
#include <bits/stdc++.h>
#include "2107095 - sadia\Gauss_elimination.cpp"
#include "2107095 - sadia\Jordan_Gauss_elimination.cpp"
#include "2107095 - sadia\LU_Decomposition.cpp"
#include "2107095 - sadia\Matrix_Inversion.cpp"
#include "2107009-Shejan\Gauss_Seidel_Iterative_Method.cpp"
#include "2107009-Shejan\Jacobi_Iterative_Method.cpp"
#include "2107009-Shejan\Rungee_Kutta_Method.cpp"
#include "2107026 - saleque\non_linear.h"
using namespace std;
int main()
{
    cout<<endl<<endl<<endl;
    cout<<"     Welcome to Numerical Methods Console Application:   "<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"1.Linear Equations"<<endl<<endl;
    cout<<"2.Non Linerar Equations"<<endl<<endl;
    cout<<"3.Differential Equation"<<endl<<endl;
    cout<<"4.Matrix Inversion"<<endl<<endl<<endl<<endl;  
    cout<<"Enter your choice:";
    int choice;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"1.Jacobi Iterative Method"<<endl;
        cout<<"2.Gauss Seidel Iterative Method"<<endl;
        cout<<"3.Gauss Elimination"<<endl;
        cout<<"4.Jordan Elimination"<<endl<<endl;
        cout<<"Enter your choice:";
        int choice1;
        cin>>choice1;
        
        switch(choice1)
        {
            case 1:
            jacobi();
            break;
            case 2:
            gauss_seidel();
            break;
            case 3:
            Gauss_Eliminations();
            break;
            case 4:
            Jordan_main();
            break;
            default:
            cout<<"Invalid Choices"<<endl;
            
        }
        break;
    case 2:
        non_linear();
        break;

    case 3:
        rungeKutta();
        break;
    case 4:
         Inverse_Matrix();
    default:
        cout<<"Invalid Choices"<<endl;
        break;
    }
    
    
}