/*
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10
Sample Output 1 :
2 3 4
10

Time Complexity: O((n*logn)+(m*logm))
Space Complexity: O(1)

A more optimized solution to this problem is possible using Hashmaps which will have
Time Complexity: O(n+m)
Space Complexity: O(min(n,m))
*/
void intersection(int *arr1,int *arr2,int n,int m){
	sort(arr1,arr1+n);
	sort(arr2,arr2+m);
	int i=0; //Pointer to iterate over arr1
	int j=0; //Pointer to iterate over arr2
	
	while(i<n && j<m){
		if(arr1[i]==arr2[j]){
			cout<<arr1[i]<<" ";
			i++;
			j++;
		}
		else if(arr1[i]<arr2[j]){
			i++;
		}
		else{
			j++;
		}
	}
}