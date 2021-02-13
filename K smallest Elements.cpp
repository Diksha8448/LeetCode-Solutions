/*
Given an array of the size n and k . Print the first k smallest elements.
Time Complexity: O(N*log(k))
Space Complexity: O(k)
*/
#include<queue>
vector<int>KSmallest(int arr[],int n,int k){
    priority_queue<int>maxHeap;
    for(int i=0;i<k;i++){
        maxHeap.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]<maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    vector<int>output;
    while(!maxHeap.empty()){
        output.push_back(maxHeap.top());
        maxHeap.pop();
    }
    return output;
}