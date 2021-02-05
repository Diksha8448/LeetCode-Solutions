/*
Given two arrays A and B of size N and M respectively. The task is to find union between these two arrays.

Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in union.

Example 1:

Input:
5 3
1 2 3 4 5
1 2 3

Output: 
5
*/

int doUnion(int a[], int n, int b[], int m)  
{
    //code here
    
	set<int> hs;
 
    
	// Insert the elements of arr1[] to set hs
    
	for (int i = 0; i < n; i++)
        
	hs.insert(a[i]);
 
    
	// Insert the elements of arr2[] to set hs
    
	for (int i = 0; i < m; i++)
        
	hs.insert(b[i]);
        
    
	return hs.size();
    

}