/*
Given an array A of random integer and an integer K, find and return the Kth largest element in the array.
Time Complexity: O(N*log(k))
Space Complexity: O(k)
*/
int KthLargest(int *arr,int n,int k){
    priority_queue<int,vector<int>,greater<int>>minHeap;
    for(int i=0;i<k;i++){
        minHeap.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]>minHeap.top()){
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    return minHeap.top();
}