/*
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.

Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2

Time Complexity: O(N)
Space Complexity: O(N)
*/
int highestfrequency(int arr[],int n){
	unordered_map<int,int>freq;
	int maxFreq=0;
	for(int i=0;i<n;i++){
		++freq[arr[i]];
		maxFreq=max(maxFreq,freq[arr[i]]);
	}
	int maxFreqElement;
	for(int i=0;i<n;i++){
		if(freq[arr[i]]==maxFreq){
			maxFreqElement=arr[i];
			break;
		}
	}
	return maxFreqElement;
}