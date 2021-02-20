/*
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.

Sample Input 1 :
ababacd
Sample Output 1 :
abcd

Time Complexity: O(N)
Space Complexity: O(1)

*/
#include<bits/stdc++.h>
string uniqueChar(string str){
    string answer;
    unordered_set<char> charSet;
    
    for(char ch:str){
        if(charSet.find(ch)==charSet.end()){
            answer.push_back(ch);
            charSet.insert(ch);
        }
    }
    return answer;
}