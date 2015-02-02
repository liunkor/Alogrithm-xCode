/*
 给定一个整型数组（元素有正数有负数），求该数组的所有子数组中和打最大值。要求时间复杂度O(n)。
 *
 */


#include <iostream>
using std::cout; using std::endl;

bool invalidInput = false;

int findMaxSumOfSubArray(int a[], int length) {
    if(a == NULL || length <= 0) {
        invalidInput = true;
        return 0;
    }

    int curSum = 0;   //初始化当前的子数组的和为0
    int maxSum = 0x80000000;  //初始化maxSum为最小打整数

    for(int i = 0; i < length; ++i) {
        if(curSum <= 0)  // 如果前面的数组之和小于等于0，则丢弃
            curSum = a[i];
        else
            curSum += a[i];

        if(curSum > maxSum)  // 如果当前的和更大，则保存为当前最大值
            maxSum = curSum;
    }
    return maxSum;
}

int main() {
    int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
    if(invalidInput)
        cout << "InvalidInput !!" << endl;
    else
        cout << "MaxSum: " << findMaxSumOfSubArray(a, 8) << endl;
}
