/*
We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Example 1:
Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
*/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) { 
        bool flag=false;
        int n=bits.size();
        for(int i=0;i<n;i++){
            if(i==n-1){
                flag=true;
            }
            if(bits[i]==1){
                i+=1;
            }
        }
        return flag;
    }
};