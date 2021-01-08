/*
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.

Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.

Example 2:

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
*/

string countAndSay(int n) {
        // Base cases 
    if (n == 1)      return "1"; 
    if (n == 2)      return "11"; 
  
    
    string str = "11"; 
    for (int i = 3; i<=n; i++) 
    { 
        
        str += '$'; 
        int len = str.length(); 
  
        int cnt = 1;  
        string  tmp = "";  
  
        for (int j = 1; j < len; j++) 
        { 
   
            if (str[j] != str[j-1]) 
            { 
   
                tmp += cnt + '0'; 
  
  
                tmp += str[j-1]; 
  
                  cnt = 1; 
            } 
  
            else cnt++; 
        } 
  
          str = tmp; 
    } 
  
    return str; 
        
}