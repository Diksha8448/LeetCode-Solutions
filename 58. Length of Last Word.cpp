/*
Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5

Example 2:

Input: s = " "
Output: 0
*/


int lengthOfLastWord(string str) {
        int count = 0; 
        bool flag = false; 
        for (int i = str.length() - 1; i >= 0; i--) { 
        
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) { 
                flag = true; 
                count++; 
            } 
        
            else { 
                if (flag == true) 
                return count; 
            } 
        } 
        return count;    
        
}