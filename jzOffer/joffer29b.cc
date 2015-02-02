/*
 *找出数组（无序）中出现次数超过数组长度一般的数字。
 思路： 用两个变量count、current。count来保存次数，遍历的过程中，如果当前元素值与current的值像等则将count增加1；若不像等则减1。如果count减为0，则要保存下一元素（current = num[i]）。
 对应要找的数字必定是最后一次把次数变为1或增加1的那个数字。
 *
 */
#include <iostream>
using std::endl; using std::cout;

bool checkInvalidInput(int *num, int length, int number) {
    int count = 0; 
    for(int i = 0; i < length; ++i) {
        if(num[i] == number)
            ++count;
    }
    if(count > length / 2)
        return true;
    
    return false;
}

void findMoreThanHalfNum(int *num, int length) {
    if(num == NULL || length <= 0)
        return;
    int count = 1;
    int current = num[0];

    for(int i = 1; i < length; ++i) {
        if(count == 0) {
            count = 1;
            current = num[i];
        } else {
            if(current == num[i])
                ++count;
            else
                --count;
        }
    }
    if(checkInvalidInput(num, length, current))
        cout << current << endl;
    else 
        cout << "InvalidInput or Not found" << endl;
}

int main() {
    int a[] = {2, 5, 9, 1, 5, 7, 5, 6, 5, 5, 2, 5, 5, 5, 7};
    findMoreThanHalfNum(a, 15);

    findMoreThanHalfNum(a, 10);


}
