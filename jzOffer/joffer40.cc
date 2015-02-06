/*
 *  给定一个整型数组，数组中只有两个数组分别只出现一次，其它数字都出现了2次。找出这两个只出现一次的数字。
 *  思路：由【如果数组中只有一个数字只出现一次,其它数字都出现2次，找出出现一次的数字】扩展而来。
 *      首先，获得2个只出现一次的数字的异或的结果。 
 *      然后，根据这个【结果绝对不可能为0】最右边的1出现在第几位，用这个位上是否为1把数组分为两个子数组。（只出现一次的这两个数肯定分别出现在这两个子数组中）
 *      最后，在子数组中用异或即分别可找出这2个数字
 */

#include <iostream>
using std::cout; using std::endl;

unsigned int findFirstBitOne(int n) {   // 查找n最右边的1出现在哪个位上。
    unsigned int indexBit = 0;
    while(((n & 1) == 0) && (indexBit < 8 * sizeof(int))) {
        ++indexBit;
        n >>= 1;
    }
    return indexBit;
}

void FindTwoNumberOccuredOnce(int *a, int length, int *num1, int *num2) {
    if(a == NULL ||length < 2)
        return;

    int index = 0;
    *num1 = *num2 = 0;
    for(int i = 0; i < length; ++i)
        index ^= a[i];
    
    int firstBitOne = findFirstBitOne(index);
    int b = 1;
    b <<= firstBitOne;

    for(int i = 0; i < length; ++i)
        if(a[i] & b)
            (*num1) ^= a[i];
        else
            (*num2) ^= a[i];

}

int main() {
    int a[] = {1, 2};
    int n1 = 0;
    int n2 = 0;
    FindTwoNumberOccuredOnce(a, 2, &n1, &n2);
    cout << n1 << " " << n2 << endl;

    int b[] = {2, 5, 9, 2, 8, 9, 6, 7, 6, 5};
    FindTwoNumberOccuredOnce(b, 10, &n1, &n2);
    cout << n1 << " " << n2 << endl;

    int c[] = {2, 8, 7, 4, 11, 11, 5, 9, 2, 8, 9, 7, 6, 5};
    FindTwoNumberOccuredOnce(c, 14, &n1, &n2);
    cout << n1 << " " << n2 << endl;

}
