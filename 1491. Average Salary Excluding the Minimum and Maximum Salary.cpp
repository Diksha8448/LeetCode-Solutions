/*
Given an array of unique integers salary where salary[i] is the salary of the employee i.

Return the average salary of employees excluding the minimum and maximum salary.

Example 1:

Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000)/2= 2500

Example 2:

Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000)/1= 2000
*/

class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end()); 
        int n=salary.size();
        double sum=0;
        int count=0;
        for(int i=1;i<=n-2;i++){
            count+=1;
            sum+=salary[i];
        }
        return sum/count;
    }
};