#include <iostream>
using namespace std;

void HeapSort(int input[], int n){
    
    int size = 0;

    // Build MaxHeap
    for(int i=0 ; i<n ; i++) {

        size++;
        int childIndex = size - 1;

        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if(input[childIndex] > input[parentIndex]) {
                swap(input[childIndex], input[parentIndex]);
            }
            else
                break;

            childIndex = parentIndex;
        }  
    }
    
    // Swap Elements and Do Max Heapify
    for(int i=0 ; i<n ; i++) {

        int parentIndex = 0;
        swap(input[0], input[size-1]);
        size--;
        int LCI = 2*parentIndex+1, RCI = parentIndex*2+2;
        
        while(LCI < size) {
            int maxIndex = parentIndex;
            
            if(input[maxIndex] < input[LCI])
                maxIndex = LCI;
            
            if(RCI < size && input[maxIndex] < input[RCI])
                maxIndex = RCI;
            
            if(parentIndex == maxIndex)
                break;
            
            swap(input[parentIndex], input[maxIndex]);
            
            parentIndex = maxIndex;
            LCI = 2*parentIndex+1;
            RCI = 2*parentIndex+2;
        }
    }
}



int main(){

    freopen("sort_input.txt", "r", stdin);  
    freopen("output.txt", "w", stdout);

    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;

    int *arr = new int[n];
    cout<<"\nEnter elements: \n";

    for(int i=0; i<n; i++)
        cin>>arr[i];

    HeapSort(arr, n);

    cout<<"\nSorted Elements: \n";
    
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"\n";

    delete [] arr;
    return 0;
}