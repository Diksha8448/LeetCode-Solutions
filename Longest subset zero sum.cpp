/*
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.

Sample Input 1:
10 
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output 1:
5
*/
#include<unordered_map>
int lengthLongestSubsetWithZeroSum(int *arr,int n){
	unordered_map<int,int>freq;
	for(int i=1;i<n;i++){
		arr[i]+=arr[i-1];
	}
	int m=0;
	
	for(int i=0;i<n;i++){
		if(arr[i]==0){
			if(m<i+1){
				m=i+1;
			}
		}else if(freq.count(arr[i])>0){
			if(m<i-freq[arr[i]]){
				m=i-freq[arr[i]];
			}
		}else{
			freq[arr[i]]=i;
		}
	}
	
	return m;
}