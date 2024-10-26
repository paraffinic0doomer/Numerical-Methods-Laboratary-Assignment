#include <bits/stdc++.h>
using namespace std;
//function to print the matrix
void print_inverse(vector<vector<float>>aug_mat,int n)
{
    cout<<fixed<<setprecision(6)<<endl;   // set precision value so that the floating point number can take up to 6 digit from decimal
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(2*n);j++)
        {


            if(aug_mat[i][j]==-0)
            {
                cout<<setw(10)<<0.000000<<" ";     //using setw to have proper alignment of matrix column
            }
            else
            {
                cout<<setw(10)<<aug_mat[i][j]<<" ";
            }

            if(j==n-1)
            {
               cout<<"    ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

//function to perform Gaussian elimination
void gauss_elimination_inverse(vector<vector<float>>&aug_mat,int n)
{
     cout<<"performing Gaussian elimination in the augmented matrix:"<<endl;      //from last row element of first column until its diagonal element the elimination is performed to make the value 0
    for(int j=0;j<n;j++)                                                          ////then the column shifts to next one to do the same
    {
        for(int i=n-1;i>j;i--)
        {

            float u=aug_mat[i][j];  //the element that is targetted to make zero
            float v=aug_mat[i-1][j];
            int e=i-1;
            if(u!=0)                               //finding the non zero row element upper than the current processing element
            {
            {
                if(v==0)
                {
                    for(int d=i-2;d>=0;d--)
                    {
                        if(aug_mat[d][j]!=0)
                        {
                            v=aug_mat[d][j];
                            e=d;
                            break;
                        }
                    }
                }
                for(int k=0;k<(2*n);k++)
            {
                aug_mat[i][k]=(aug_mat[i][k]*v)-(aug_mat[e][k]*u);   //performing matrix row operation to make the elements under pivot zero
                print_inverse(aug_mat,n);

            }
            }





        }

    }
}
}
//performing Jordan elimination
void jordan_elimination_inverse(vector<vector<float>>&aug_mat,int n)
{
   cout<<"performing Jordan elimination in the augmented matrix:"<<endl; // from last column's first row element the operation begins until the diagonal element
    for(int j=n-1;j>0;j--)                                                //then it shifts to previous column to do the same
    {
        for(int i=0;i<j;i++)
        {

            float u=aug_mat[i][j];   //the element that is targetted to make zero
            float v=aug_mat[i+1][j];
            int e=i+1;

          if(u!=0)             //finding non zero row element below the processing element
          {
              if(v==0)
                {
                    for(int d=i+2;d<n;d++)
                    {
                        if(aug_mat[d][j]!=0)
                        {
                            v=aug_mat[d][j];
                            e=d;
                            break;
                        }
                    }
                }
                 for(int k=0;k<(2*n);k++)
            {
                aug_mat[i][k]=(aug_mat[i][k]*v)-(aug_mat[e][k]*u);       //finding non zero row element below the processing element
                print_inverse(aug_mat,n);
            }

          }





        }

    }
}
//performing row echalon method to make the pivot elements one
void row_echelon_inverse(vector<vector<float>>&aug_mat,int n)
{
    cout<<"performing row echalon in the augmented matrix:"<<endl;
    for(int i=0;i<n;i++)
    {   float w=aug_mat[i][i];
    if(w!=0)
    {
                for(int j=0;j<(2*n);j++)
        {
            aug_mat[i][j]=(aug_mat[i][j]/w);
            print_inverse(aug_mat,n);
        }
    }


    }
}

//function which will be called from main function to output inverse of any matrix
void Inverse_Matrix()
{
     int n;
    cout<<"matrix size:"<<endl;
    cin>>n;
    cout<<"give the elements of matrix:"<<endl;
    vector<vector<float>>mat;

    for(int i=0;i<n;i++)
    {

        vector<float>temp;
        for(int j=0;j<(n);j++)
        {
            float x;

            cin>>x;
            temp.push_back(x);
        }
        mat.push_back(temp);
    }
    cout<<"the original matrix is:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n+1);j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    vector<vector<float>>aug_mat(n,vector<float>(2*n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            aug_mat[i][j]=mat[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=n;j<(2*n);j++)
        {
            if(i==(j-n))
            {
                aug_mat[i][j]=1;
            }
            else
            {
                aug_mat[i][j]=0;
            }
        }
    }
   cout<<"the augmented matrix is:"<<endl;
   print_inverse(aug_mat,n);
   gauss_elimination_inverse(aug_mat,n);
   jordan_elimination_inverse(aug_mat,n);
   row_echelon_inverse(aug_mat,n);
   cout<<"after all operation the augmented matrix is:"<<endl;
   print_inverse(aug_mat,n);
   cout<<"So the inverse matrix of the given matrix is:"<<endl;   // the colum from n to 2n-1 is the inverse matrix
   cout<<fixed<<setprecision(6)<<endl;
   for(int i=0;i<n;i++)
   {
       for(int j=n;j<(2*n);j++)
       {
           if(aug_mat[i][j]==-0)
            {
                cout<<setw(10)<<0.000000<<" ";
            }
            else
            {
                cout<<setw(10)<<aug_mat[i][j]<<" ";
            }
       }
       cout<<endl;
   }

}




