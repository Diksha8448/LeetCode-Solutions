/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 10^6
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
*/
/*
Time Complexity: O(N)
Space Complexity: O(N)

where N is the final height of the binary tree
*/
#include<vector>
int balancedBTs(int n){
    vector< long long> dp(n+1); //dp[i] represents number of balances BTs of height i
    if(n<=1){
        return 1;
    }
    dp[0]=1;
    dp[1]=1;
    int mod = 1e9+7;

    for(int i=2;i<=n;++i){
       long long int temp1=dp[i-1]*dp[i-1];
       temp1=temp1%mod;

       long long int temp2=2*dp[i-1]*dp[i-2];
       temp2=temp2%mod;

       dp[i] = (temp1+temp2)%mod;
    }

    return dp[n];
}