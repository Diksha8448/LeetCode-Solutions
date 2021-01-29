/*
Matrix Chain Multiplication

Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of dimension p[i-1] x p[i]. We need to write a function MatrixChainOrder() that should return the minimum number of multiplications needed to multiply the chain. 

Input: p[] = {40, 20, 30, 10, 30}   
Output: 26000  
There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

*/

int mcm(int arr){
  int **dp=new int[arr.size()-1][arr.size()-1];
  for(int g=0;g<dp.size();g++){
   for(int i=0,j=g;j<dp.size();i++){
     if(g==0)
       dp[i][j]=0;
     else if(g==1)
       dp[i][j]=arr[i]*arr[j]*arr[j+1];
     else{
       int min=INT_MAX;
       for(int k=i;k<j;k++){
         //dp->i, k left half and k+1,j right half
         //arr->i*(k+1) left half, (k+1)*(j+1) right half
         int lc=dp[i][k];
         int rc=dp[k+1][j];
         int mc=arr[i]*arr[k+1]*arr[j+1];
         int tc=lc+rc+mc;
         if(tc<min)
           min=tc;
       }
       dp[i][j]=min;
     }
   }
  }
  return dp[0][dp.size()-1];
}