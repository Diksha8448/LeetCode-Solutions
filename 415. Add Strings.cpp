/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

1.The length of both num1 and num2 is < 5100.
2.Both num1 and num2 contains only digits 0-9.
3.Both num1 and num2 does not contain any leading zero.
4.You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int a,b,sum,carry=0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        while(i>=0 || j>=0){
            a = (i>=0) ? num1[i]-'0' : 0; 
            b = (j>=0) ? num2[j]-'0' : 0; 
            sum = a+b+carry;
            carry = sum/10;
            sum = sum%10;
            result.push_back('0' + sum);
            i--;
            j--;
        }
        
        if(carry)
            result.push_back('0' + carry);
        reverse(result.begin(),result.end());
        return result;
    }
};