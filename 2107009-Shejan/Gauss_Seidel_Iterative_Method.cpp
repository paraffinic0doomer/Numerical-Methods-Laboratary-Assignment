#include <bits/stdc++.h>
using namespace std;
bool gauss_seidel()
{
    int var;
    cout<<"Number of variables:";
    cin>>var;
    vector<vector<int>> arr;
    cout<<"Enter the coefficients of the variable and constants:"<<endl;
    for(int i=0;i<var;i++)
    {   
        char o='a';
        vector<int> temp;
        for(int j=0;j<var+1;j++)
        {
            int m;
            cout<<"value of "<<o<<i<<" :"<<endl;
            cin>>m;
            o++;
            temp.push_back(m);
        }
        arr.push_back(temp);
        
    }
    int x=0;
     for (int i = 0; i < var; ++i) {
        int diagonalElement = abs(arr[i][i]);
        int rowSum = 0;

        for (int j = 0; j < var; ++j) {
            if (i != j) {
                rowSum += abs(arr[i][j]);
            }
        }

        // Check if diagonal element is greater than or equal to row sum
        if (diagonalElement < rowSum) {
          x=1;
        }
    }
    if(x==1)
    {
        cout<<"Diagonally Not dominant";
        return false;
    }
    double tolerance=1e-6;
    double max_iter=100;
    vector<double> x1(var,0);
    for(int iter=0;iter<max_iter;iter++)
    {
            double error=0;
            for(int i=0;i<var;i++)
            {
                double sum=arr[i][var];
                for(int j=0;j<var;j++)
                {
                    if(i!=j)
                    {
                        sum-=arr[i][j]*x1[j];
                    }
                }
                double x_new=sum/arr[i][i];
                error+=abs(x_new-x1[i]);
                x1[i]=x_new;
            }
            if(error<tolerance)
            {
                break;
            }
    }
    cout<<endl;
    cout<<"Solution:"<<endl;
    for(int i=0;i<var;i++)
    {
        if(x1[i]==-0)
        cout<<"x"<<i<<0<<endl;
        else
        cout<<"x"<<i<<"="<<x1[i]<<" ";
    }
    return true;
}
