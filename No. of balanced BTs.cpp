
/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 24
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
*/
/*
Time Complexity: O(2^N)
Space Complexity: O(N)

where N is the final height of the binary tree
*/
int balancedBTs(int n){
    if(n<=1){
        return 1;
    }

    int mod=1e9+7;
    int x=balancedBTs(n-1);
    int y=balancedBTs(n-2);

    long long int temp1=((long long int)x*x)%mod; //Number of BTs made by attaching subtrees of height (n-1) at both sides of root
    long long int temp2=(2*(long long int)x*y)%mod;// Number of BTs made by attaching subtrees of heightd (n-1) and (n-2) at each side of root
    long long int ans=(temp1+temp2)%mod;

    return ans;
}