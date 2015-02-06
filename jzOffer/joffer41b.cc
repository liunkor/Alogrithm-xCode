/*
 * 输入一个正整数sum， 输出所有和为sum的连续正数序列（至少含有2个数）
 *
 */

#include <iostream>
using std::cout; using std::endl;

void printContinueSequence(int sum) {
    if(sum < 3)
        return;

    int beg = 1;
    int end = sum / 2;
    if(end % 2 == 1)
        ++end;

    int i = beg;
    unsigned long long curSum = i;

    while(beg < end) {
        if(curSum < sum) {
            if(i >= end)            // 循环出口 
                return;
            ++i;
            curSum += i;
        } else if(curSum == sum) {
            for(int j = beg; j <= i; ++j)
                cout << j << " ";
            cout << endl;

            if(i < end) {
                ++i;
                curSum += i;
            } else              // i >= end 循环出口
                return;
        } else {                // curSum > sum
            curSum -= beg;
            ++beg;
        }
    }
}

int main() {
   cout << "sum = 2 " << endl;
   printContinueSequence(2);
   cout << "sum = 6 " << endl;
   printContinueSequence(6);
   cout << "sum = 15 " << endl;
   printContinueSequence(15);
}
