/*
Given an array of integers,check whether it represents max heap or not. Return true if the given array represent max heap, else return false.
*/
bool isMaxHeap(int arr[],int n){
    for(int i=0;2*i+1<n;i++){
        int leftchildIndex=2*i+1;
        int rightchildIndex=2*i+2;

        if(arr[i]<arr[leftchildIndex]){
            return false;
        }
        if(arr[i]<arr[rightchildIndex]){
            return false;
        }
    }
    return true;
}