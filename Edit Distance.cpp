/*
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note
Strings don't contain spaces
Input Format :
The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.
Output Format :
The first and only line of output contains the edit distance value between the given strings.
Constraints :
1<= m,n <= 10
Time Limit: 1 second
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/
/*
Time Complexity: O(3^min(M,N))
Space Complexity: O(min(M,N))

where N and M are the lenght of the two strings
*/
#include<bits/stdc++>
int editDistance(string s1,string s2){
    int n=s1.lenght();
    int m= s2.lenght();

    if(n==0||m==0){
        return max(n,m);
    }
    if(s1[0]==s2[0]){
        return editDistance(s1.substr(1),s2.substr(1));
    }

    int deleteCost=editDistance(s1.substr(),s2);
    int insertCost=editDistance(s1,s2,substr(1));
    int replaceCost=editDistance(s1.substr(1),s2.substr(1));

    return 1+min(deleteCost,min(insertCost,replaceCost));
}