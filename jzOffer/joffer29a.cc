/*
 *找出数组（无序）中出现次数超过数组长度一般的数字。
 思路： 对数组重复利用“一次快排”,直到partition返回值等于length/2，即找到！
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

int partition(int *num, int low, int high) {
    int index = num[high];
    int i = low - 1;
    for(int j = low; j < high; ++j) { 
        if(num[j] < index) {
            ++i;
            if(i != j){
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
            
       } 
    }
    ++i;
    int temp = num[i];
    num[i] = num[high];
    num[high] = temp;
    return i;
}
void findMoreThanHalfNum(int *num, int length) {
    if(num == NULL || length <= 0)
        return;

    int mid = length >> 1;
    int low = 0; 
    int high = length - 1;
    int index = partition(num, low, high);

    while(index != mid) {
        if(index < mid) 
            low = low + 1;
        else
            high = high - 1;
        index = partition(num, low, high);
    }
    if(checkInvalidInput(num, length, num[index]))
        cout << num[index] << endl;
    else 
        cout << "InvalidInput or Not found" << endl;

}

int main() {
    int a[] = {2, 5, 9, 1, 5, 7, 5, 6, 5, 5, 2, 5, 5, 5, 7};
    findMoreThanHalfNum(a, 15);
}
