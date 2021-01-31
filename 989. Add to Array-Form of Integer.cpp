/*
For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.

 

Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n=A.size();
        int cur=K;
        vector<int>arr;
        int i=n;
       
        while (--i >= 0 || cur > 0) {
            if (i >= 0)
                cur += A[i];
            arr.push_back(cur % 10);
            cur /= 10;
        }
        reverse(arr.begin(), arr.end()); 
        return arr;
    }
};