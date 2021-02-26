/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.

 Input format :
The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.

Output format :
Print the minimum cost to reach the destination.
Constraints :
1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec

Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1

Sample Output 1 :
13
*/
/*
Time Complexity: O(3^P) where P=(M*N)
Space Complexity: O(max(M,N))

where M and N are the rows and columns of the input matrix
*/
#include<climits>
#include<math.h>
int minCostPathHelper(int **input,int m,int n,int i,int j){
    if(i>=m||j>=n){
        return INT_MAX;
    }else if(i==m-1 && j==n-1){
        return input[i][j];
    }

    int downCost=minCostPathHelper(input,m,n,i+1,j);
    int diagonalCost=minCostPathHelper(input,m,n,i+1,j+1);
    int leftCost=minCostPathHelper(input,m,n,i,j+1);

    return input[i][j]+min(diagonalCost,min(downCost,leftCost));
}
int minCostPath(int **input,int m,int n){
    return minCostPathHelper(input,m,n,0,0);
}