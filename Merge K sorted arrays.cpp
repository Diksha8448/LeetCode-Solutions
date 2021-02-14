/*
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.

Sample Input 1:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1:
0 1 2 5 6 9 45 78 90 100 234

Time Complexity: O(k*N*log(k*N))
Space Complexity: O(k*N)
*/
#include<queue>
vector<int>mergeSortedArray(vector<vector<int>*>input){
	vector<int>mergedArray;
	priority_queue<int,vector<int>,greater<int>>minHeap;
	for(int i=0;i<input.size();i++){
		for(int j=0;j<input[i]->size();j++){
			minHeap.push(input[i]->at(j));
		}
	}
	while(!minHeap.empty()){
		mergedArray.push_back(minHeap.top());
		minHeap.pop();
	}
	return mergedArray;
}
