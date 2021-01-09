/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/
This method uses the technique of Sliding Window to arrive at the solution.

Approach: This method efficiently implements the above Dynamic Programming approach.
In this approach for the ith stair, we keep a window of sum of last m possible stairs from which we can climb to the ith stair. Instead of running an inner loop, we maintain the result of the inner loop in a temporary variable. We remove the elements of the previous window and add the element of the current window and update the sum.

int climbStairs(int n) {
        int res[n + 1]; 
        int m=2;
        int temp = 0; 
        res[0] = 1; 
        for (int i = 1; i <= n; i++) 
        { 
            int s = i - m - 1; 
            int e = i - 1; 
            if (s >= 0) 
            { 
                temp -= res[s]; 
            } 
            temp += res[e]; 
            res[i] = temp; 
        } 
        return res[n]; 
}