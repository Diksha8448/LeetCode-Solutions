/*
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  

Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 

Time Complexity: O(N)
Space Complexity: O(N)
*/
int countStepsToOne(int n){
	int *minSteps=new int[n+1];
	minSteps[1]=0;
	
	for(int i=2;i<=n;++i){
		int substractOne=minSteps[i-1];
		int divideByTwo=INT_MAX;
		int divideByThree=INT_MAX;
		
		if(i%2==0){
			divideByTwo=minSteps[i/2];
		}
		if(i%3==0){
			divideByThree=minSteps[i/3];
		}
		minSteps[i]=1+min(substractOne,min(divideByTwo,divideByThree));
	}
	
	int result=minSteps[n];
	delete[] minSteps;
	return result;
}

