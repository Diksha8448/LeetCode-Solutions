/*
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.

Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2

*/
#include<unordered_map>
int pairSum(int *arr,int n){
	unordered_map<int,int>freq;
	int pairCount=0;
	
	for(int i=0;i<n;++i){
		int complement=-arr[i];
		if(freq.find(complement)!=freq.end()){
			pairCount+=freq[complement];
		}
		
		++freq[arr[i]];
	}
	return pairCount;
}
