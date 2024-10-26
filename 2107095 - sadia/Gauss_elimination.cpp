#include <bits/stdc++.h>
using namespace std;
// function to display the matrix
void print_gauss(vector<vector<float>>mat,int n)
{   
    cout<<fixed<<setprecision(6)<<endl;  // set precision value so that the floating point number can take up to 6 digit from decimal
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n+1);j++)
        {
            if(mat[i][j]==-0)
            {
                cout<<setw(10)<<0.000000<<" ";   //using setw to have proper alignment of matrix column
            }
            else
            { 
                cout<<setw(10)<<mat[i][j]<<" ";

            }
            
        }
        cout<<endl;
    }
    cout<<endl;
}
//function to perform the Guassian elimination
void Gaussian_function(vector<vector<float>>&mat,int n)
{

    for(int j=0;j<n;j++)
    {
        for(int i=n-1;i>j;i--)
        {                            //from last row element of first column until its diagonal element the elimination is performed to make the value 0
                                 //then the column shifts to next one to do the same

            float u=mat[i][j];  //the element that is targetted to make zero
            float v=mat[i-1][j];
            int e=i-1;
            if(u!=0)  //finding the non zero row element upper than the current processing element
            {
                if(v==0)
                {
                    for(int d=i-2;d>=0;d--)
                    {
                        if(mat[d][j]!=0)
                        {
                            v=mat[d][j];
                            e=d;
                            break;
                        }
                    }
                }
                for(int k=0;k<(n+1);k++)
            {
                mat[i][k]=(mat[i][k]*v)-(mat[e][k]*u); //performing matrix row operation to make the elements under pivot zero
                print_gauss(mat,n);
            }
            }





        }

    }
}
//function which will be called from main function to do Gaussian elimination
void Gauss_Eliminations()
{
    int n;
    cout<<"number of unknowns:"<<endl;
    cin>>n;
    cout<<"give the values of coefficients of variable:"<<endl;
    vector<vector<float>>mat;
    for(int i=0;i<n;i++)
    {   
        char o='a';
        vector<float>temp;
        for(int j=0;j<(n+1);j++)
        {
            float x;
            cout<<"value of"<<o<<i<<":"<<endl;
            cin>>x;
            o++;
            temp.push_back(x);
        }
        mat.push_back(temp);
    }
    cout<<"before any operation:"<<endl;
   print_gauss(mat,n);
   Gaussian_function(mat,n);
    cout<<"after gauss elemination:"<<endl;
    print_gauss(mat,n);
}

