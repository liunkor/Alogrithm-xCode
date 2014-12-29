/*
 *Remove Duplicates from Sorted Array
 * 
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2]. 
 */

/*
 *思路：1.对数组元素个数为0个、1个的情况进行处理
        2.对数组元素个数>=2个的情况进行处理：两个下标pre、curr。pre始终表示不重复的元素中最后一个元素的下标，curr为当前需要进行判断处理的元素下标。
 */

#include <iostream>
using std::cout; using std::endl;

int removeDuplicates(int A[], int n) {
        if(A == 0 || n == 0) 
            return 0;
        if(A != NULL && n == 1)   // 自己犯的错误：用||替代了&&,结果始终返回1
            return 1;
        
        int pre = 0, curr = 1;
        while(curr < n) {
            if(A[pre] != A[curr]) {
                A[++pre] = A[curr];
            }
             ++curr;
        }
        
        return pre + 1;
}

//使用STL
/*
 int removeDuplicates(int A[], int n) {
    return distance(A, unique(A, A + n));
 }
 */

int main() {
    int a[] = {1, 2};
    int newLength = removeDuplicates(a, 2);
    cout << newLength << endl;
    for(int i = 0; i < newLength; i++)
        cout << a[i] << " ";
    cout << endl;
}

