/*
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the returned length.
*/

int removeDuplicates(vector<int>& nums) {
        vector<int> original;
        vector<int> :: iterator it;
        for(it=nums.begin();it!=nums.end();it++){
            int ele=*it;
            if(find(original.begin(),original.end(),ele)!=original.end()){
                nums.erase(it);
                it--;
            }
            else{
                original.push_back(*it);
            }
        }
        return nums.size();
        
        /* Not for interview purpose but this also gives the answer and is rather more faster
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return nums.size();
        */
 }