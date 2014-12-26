/*Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321 
*/
class Solution {
    /*
    需要注意的地方：
        1.对负数的处理，符号
        2.对逆置后可能出现的溢出进行判断，这里对溢出情况直接返回 0
        3.res > 0x7FFFFFFF || res < (signed int)0x80000000，注意要将0x强制转为 signed int
    */
public:
    int reverse(int x) {  
        if(x == 0) 
    		return 0;
    	bool flag = false;
    	if(x < 0) {
    		flag = true;
    		x = -x;
    	}
    
    	long long res = 0;
    	while(x != 0) {
    		res = res * 10 + x % 10;
    		if(res > 0x7FFFFFFF || res < (signed int)0x80000000)
		    	return 0;
    		x /= 10;
    	}
    	if(flag) 
    		res = -res;
    	return res;

    }
};
