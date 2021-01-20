/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/
int uniquePaths(int m, int n) {
        if(m==1 && n==1)
            return 1;
        if(m==0 ||n==0)
            return 0;
        int mat[m][n];
        for(int i=0;i<m;i++){
            mat[i][0]=1;
        }
        for(int j=0;j<n;j++){
            mat[0][j]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j]=mat[i-1][j]+mat[i][j-1];
            }
        }
        return mat[m-1][n-1];
}