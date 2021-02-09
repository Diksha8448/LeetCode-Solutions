/*
Given a Romal numeral, the task is to find its corresponding decimal value.
Example : 

Input: IX
Output: 9
IX is a Roman symbol which represents 9 

Input: XL
Output: 40
XL is a Roman symbol which represents 40

Input: MCMIV
Output: 1904
M is a thousand, 
CM is nine hundred and 
IV is four
*/
// Returns decimal value of
// roman numaral
int romanToDecimal(string& str)
{
    // Initialize result
    int res = 0;
 
    // Traverse given input
    for (int i = 0; i < str.length(); i++) 
    {
        // Getting value of symbol s[i]
        int s1 = value(str[i]);
 
        if (i + 1 < str.length()) 
        {
            // Getting value of symbol s[i+1]
            int s2 = value(str[i + 1]);
 
            // Comparing both values
            if (s1 >= s2) 
            {
                // Value of current symbol
                // is greater or equal to
                // the next symbol
                res = res + s1;
            }
            else
            {
                // Value of current symbol is
                // less than the next symbol
                res = res + s2 - s1;
                i++;
            }
        }
        else {
            res = res + s1;
        }
    }
    return res;
}
 