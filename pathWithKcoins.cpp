#include<iostream>
using namespace std;

int rec(int **mat, int Rows, int Cols, int k,int i,int j, int sum){
    
    sum += mat[i][j];
    if( sum == k && i == Rows-1 && j == Cols-1 ) return 1;
    if( sum > k) return 0;
   
        
    int down =0, right =0;
    if (i+1 < Rows) {
        down = rec(mat,Rows,Cols,k,i+1,j,sum);
    }
        
    if (j+1 < Cols) {
        right = rec(mat,Rows,Cols,k,i,j+1,sum);
    }
        
    return down + right;
    
    
}


int FindPathsWithKCoins(int **mat, int Rows, int Cols, int k){ 
  /*  for(int i =0 ;i<Rows;i++)
    {
        for(int j=0;j<Cols;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }*/
    return rec(mat, Rows, Cols, k, 0, 0, 0) ;
}


