/*
You are given a stream of N integers. For every i-th integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.

Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

Time Complexity: O(N*logN)
Space Complexity:O(N)
*/
#include<queue>
void printRunningMedian(int *arr,int n){
	priority_queue<int, vector<int>,greater<int>>minHeap;
	priority_queue<int>maxHeap;
	//for each element in data stream
	for(int i=0;i<n;i++){
		if(maxHeap.size()&&arr[i]>maxHeap.top()){
			minHeap.push(arr[i]);
		}else{
			maxHeap.push(arr[i]);
		}
		if(abs((int)maxHeap.size()-(int)minHeap.size())>1){
			if(maxHeap.size()>minHeap.size()){
				int temp=maxHeap.top();
				maxHeap.pop();
				minHeap.push(temp);
			}else{
				int temp=minHeap.top();
				minHeap.pop();
				maxHeap.push(temp);
			}
		}
		int median;
		int totalsize=maxHeap.size()+minHeap.size();
		
		//when no of elements is odd
		if(totalsize%2==1){
			if(maxHeap.size()>minHeap.size()){
				median=maxHeap.top();
			}else{
				median=minHeap.top();
			}
		}
		//when no of elements is even 
		else{
			median=0;
			if(!maxHeap.empty())
				median+=maxHeap.top();
			if(!minHeap.empty())
				median+=minHeap.top();
			median/=2;
		}
		cout<<median<<" ";
	}
}