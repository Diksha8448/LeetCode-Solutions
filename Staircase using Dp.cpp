/*
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.
 Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1:
4
Sample Output 1:
7

Time Complexity: O(N)
Space Complexity: O(N)
*/
long staircase(int n){
	long *ways=new long[n+1];
	//Base cases
	if(n==0){
		return 1;
	}
	if(n==1||n==2){
		return n;
	}
	
	ways[0]=1;
	ways[1]=1;
	ways[2]=2;
	for(int i=3;i<=n;++i){
		ways[i]=ways[i-1]+ways[i-2]+ways[i-3];
	}
	
	long result=ways[n];
	
	delete[] ways;
	
	return result;
}
