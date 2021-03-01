/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example 1:

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
*/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0 , row = grid.size(), col = grid[0].size();    
        for(int i = 0 ; i < row ; i++)
        {
           for(int j = 0 ; j < col ; j++)
           {
               if( grid[i][j])
               {
                  ans+=4;
                  if(i < row - 1 && grid[i+1][j])ans--; 
                  if(j < col -1 && grid[i][j+1])ans--; 
                  if(j  && grid[i][j-1])ans--; 
                  if(i  && grid[i-1][j])ans--; 
               }
           } 
        }
        return ans;
    }
};