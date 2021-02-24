/*
You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.

Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2
*/
#include<unordered_map>
int getPairsWithDifferenceK(int *arr,int n,int k){
	unordered_map<int,int>freq;
	
	int pairCount=0;
	
	for(int i=0;i<n;++i){
		int complement=arr[i]+k;
		pairCount+=freq[complement];
		
		if(k!=0){
			complement=arr[i]-k;
			pairCount+=freq[complement];
		}
		
		++freq[arr[i]];
	}
	return pairCount;
}