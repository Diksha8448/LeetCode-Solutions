/*Given a 32-bit signed integer, reverse digits of an integer.

Input: x = 123
Output: 321

Input: x = -123
Output: -321

Input: x = 120
Output: 21
*/
int reverse(int x) {
        long int num=0;
        if(x>=2147483647||x<=-2147483647){
            return 0;
        }
        if(x>0){
            while(x>0){
                num=num*10;
                if(num>=2147483647||num<=-2147483647){
                    return 0;
                }
                num=num+(x%10);
                x=x/10;
            }
        }
        else{
            x=-1*x;
            while(x>0){
                num=num*10;
                if(num>=2147483647||num<=-2147483647){
                    return 0;
                }
                num=num+(x%10);
                x=x/10;
            }
            num=-1*num;
        }
        return int(num);
}
