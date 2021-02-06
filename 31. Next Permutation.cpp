/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),k,l;
        //we have started from n-2 because the breakpoint might start from second
        // last element so, here k is the breakpoint 
        //loop to find out the breakpoint
        for(k=n-2;k>=0;k--){
            if(nums[k]<nums[k+1]){
                break;
            }
        }
        // means if the we did not find any break point that we are on the last set of 
        // permutation for example for 54321 the k<0 so we will return 12345
        if(k<0){
            reverse(nums.begin(),nums.end());
        }else{
            //for finding next number smaller than k i.e.l
            for(l=n-1;l>k;l--){
                if(nums[l]>nums[k]){
                    break;
                }
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
        
    }
};