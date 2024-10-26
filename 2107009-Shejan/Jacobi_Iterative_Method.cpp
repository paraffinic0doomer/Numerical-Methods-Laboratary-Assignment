#include <bits/stdc++.h>
using namespace std;
bool jacobi()
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
    vector<double> x1_new(var);
    for(int iter=0;iter<max_iter;iter++)
    {
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
                x1_new[i]=sum/arr[i][i];
            }
            double error=0;
            for(int i=0;i<var;i++)
            {
                error+=abs(x1_new[i]-x1[i]);
                if(error<tolerance)
                break;
            }
            x1=x1_new;
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
