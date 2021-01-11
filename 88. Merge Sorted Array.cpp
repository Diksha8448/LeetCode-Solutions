/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, key, j;
        for (i = m; i < m+n; i++)
        {
            key = nums2[i-m];
            j = i - 1;
            while (j >= 0 && nums1[j] > key)
            {
                nums1[j + 1] = nums1[j];
                j = j - 1;
            }
            nums1[j + 1] = key;
        }
}