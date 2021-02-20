/*
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 12 

*/
#include<bits/stdc++.h>
vector<int>longestConsecutiveIncreasingSequence(int *arr,int n){
    unordered_map<int,bool>visitedElements;
    unordered_map<int,int>elementToIndexMapping;

    for(int i=0;i<n;i++){
        elementToIndexMapping[arr[i]]=i;

        if(visitedElements.count(arr[i])==0){
            visitedElements[arr[i]]=true;
        }
    }

    vector<int> longestSequence;
    int globalMaxSequenceLength=1;
    int globalMinStartIndex=0;

    for(int i=0;i<n;i++){
        int num=arr[i];
        int currentMinStartIndex=i;
        int count=0;
        int tempNum=num;

        //Forward
        while(visitedElements.count(tempNum)==1 && visitedElements[tempNum]==true){
            visitedElements[tempNum]=false;
            count++;
            tempNum++;
        }

        //Backward
        while(visitedElements.count(tempNum)==1 && visitedElements[tempNum]==true){
            visitedElements[tempNum]=false;
            count++;

            currentMinStartIndex=elementToIndexMapping[tempNum];
            tempNum--;
        }

        if(count>globalMaxSequenceLength){
            globalMaxSequenceLength=count;
            globalMinStartIndex=currentMinStartIndex;
        }else if(count==globalMaxSequenceLength){
            if(currentMinStartIndex<globalMinStartIndex){
                globalMinStartIndex=currentMinStartIndex;
            }
        }
    }

    int globalStartNum=arr[globalMinStartIndex];
    longestSequence.push_back(globalStartNum);
    if(globalMaxSequenceLength>1){
        longestSequence.push_back(globalStartNum+globalMaxSequenceLength-1);
    }

    return longestSequence;
}