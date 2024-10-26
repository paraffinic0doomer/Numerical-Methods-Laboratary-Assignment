#include <bits/stdc++.h>
using namespace std;
//function to print the matrix
void print(vector<vector<float>>mat,int n)
{
    cout<<fixed<<setprecision(6)<<endl;  // set precision value so that the floating point number can take up to 6 digit from decimal
    for(int i=0;i<n;i++)
    {   

        for(int j=0;j<(n+1);j++)
        {  
            if(mat[i][j]==-0)
            {
                cout<<setw(10)<<0.000000<<" ";    //using setw to have proper alignment of matrix column
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
//function to perform Gaussian elimination
void gauss_elemination(vector<vector<float>>&mat,int n)
{
    cout<<"performing Gaussian elimination:"<<endl;    //from last row element of first column until its diagonal element the elimination is performed to make the value 0
    for(int j=0;j<n;j++)                              //then the column shifts to next one to do the same
    {
        for(int i=n-1;i>j;i--)
        {

            float u=mat[i][j];      //the element that is targetted to make zero
            float v=mat[i-1][j];
            int e=i-1;
            if(u!=0)                 //finding the non zero row element upper than the current processing element
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
                mat[i][k]=(mat[i][k]*v)-(mat[e][k]*u);   //performing matrix row operation to make the elements under pivot zero
                print(mat,n);
            }
            }





        }

    }
}
//performing Jordan elimination
void jordan_elemination(vector<vector<float>>&mat,int n)
{
    cout<<"performing Jordan elimination:"<<endl;  // from last column's first row element the operation begins until the diagonal element
                                                   //then it shifts to previous column to do the same
    for(int j=n-1;j>0;j--)                         
    {
        for(int i=0;i<j;i++)
        {

            float u=mat[i][j];       //the element that is targetted to make zero
            float v=mat[i+1][j];
            int e=i+1;

          if(u!=0)  //finding non zero row element below the processing element
          {
              if(v==0)
                {
                    for(int d=i+2;d<n;d++)
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
                mat[i][k]=(mat[i][k]*v)-(mat[e][k]*u);  //finding non zero row element below the processing element
                print(mat,n);
            }

          }





        }

    }
}
//performing row echalon method to make the pivot elements one to make the matrix identity
void row_echalon(vector<vector<float>>&mat,int n)
{   
    cout<<"performing Row Echalon :"<<endl;
    for(int i=0;i<n;i++)
    {   float w=mat[i][i];
    if(w!=0)
    {
                for(int j=0;j<(n+1);j++)
        {
            mat[i][j]=(mat[i][j]/w);
            print(mat,n);
        }
    }


    }
}
//to check if the pivot is zero ,if zero then it is swapped with any other non pivot row below than this
void is_pivot_zero(vector<vector<float>>&mat,int n)
{

    for(int i=0;i<n;i++)
    {
        if(mat[i][i]==0)
        {

            for(int k=i+1;k<n;k++)
            {
                if(mat[k][i]!=0)
                {

                    swap(mat[i],mat[k]);
                    break;
                }
            }
        }
    }

}

//function to check the solution type of equations
void solution_type(vector<vector<float>>&mat,int n)
{
    int h=0;
    cout<<"the solution type is:"<<endl;
    for(int i=0;i<n;i++)
    {
       if(mat[i][i]==0 && mat[i][n]==0)
       {
           cout<<"infinite many solutions"<<endl;
           h++;
           break;
       }
       else if(mat[i][i]==0 && mat[i][n]!=0)
       {
           cout<<"no solutions"<<endl;
           h++;
           break;
       }

    }
    if(h==0)
    {
        cout<<"unique solutions"<<endl;
    }
}

//the function which will be called from main to do Gauss _Jordan
void Jordan_main()
{
    int n;
    cout<<"number of unknowns:"<<endl;
    cin>>n;
    vector<vector<float>>mat;
    cout<<"give the value of coefficients of the equations:"<<endl;
    for(int i=0;i<n;i++)
    {
        vector<float>temp;
        char o='a';
        for(int j=0;j<(n+1);j++)
        {
            float x;
            cout<<"value of "<<o<<i<<":"<<endl;
            cin>>x;
            temp.push_back(x);
            o++;
        }
        mat.push_back(temp);
    }
    cout<<"before any operation:"<<endl;
   print(mat,n);

    gauss_elemination(mat,n);
    cout<<"after gauss elemination:"<<endl;
    print(mat,n);
   jordan_elemination(mat,n);
   cout<<"after jordan elemination:"<<endl;
    print(mat,n);
    row_echalon(mat,n);
    cout<<"after row echalon:"<<endl;
   print(mat,n);
    is_pivot_zero(mat,n);
    solution_type(mat,n);

}


