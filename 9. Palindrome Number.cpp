/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: x = 121
Output: true

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Example 4:

Input: x = -101
Output: false
 

Constraints:

-2^31 <= x <= 2^31 - 1
*/

bool isPalindrome(int x) {
        if(x<0||x>=2147483647)
            return false;
        long int num=0;
        int y=x;
        while(x>0){
            num=num*10;
            if(num>2147483647)
                return false;
            num=num+(x%10);
            x=x/10;
        }
        if(num==y)
            return true;
        else
            return false;
        
}