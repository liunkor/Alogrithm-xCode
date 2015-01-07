/*
 
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

/*
 思路一：根据排序好的数字序列被旋转后的特征，可将序列分为 2 个有序的子序列。
       首先，找到前后两个序列相邻的元素下标；
       然后，对两个子序列分别利用二分查找
 */

int binarySearch(int A[], int low, int high, int target) {
    int mid = (low + high) / 2;
    while(low <= high) {
        if(A[mid] == target) 
            return mid;
        else if(A[mid] > target) 
            high = mid - 1;
        else
            low = mid + 1;

        mid = (low + high) / 2;
    }
    return -1;
}

int search(int A[], int n, int target) {
    if(A == NULL || n <= 0)
        return -1;
    if(n == 1 && A[0] != target)
        return -1;
    else if(n == 1 && A[0] == target)
        return 0;

    int i = 0;
    int firstEnd = 0, secondBeg  = 0;
    while(i < n) {
        if(A[i] == target)
            return i;
        if(A[i] > A[i + 1]) {
            firstEnd = i;
            secondBeg = i + 1;
            break;
        }
        ++i;
    }

    int result = binarySearch(A, 0, firstEnd, target);
    if(result != -1)
        return result;
    result = binarySearch(A, secondBeg, n - 1, target);

    return result;
}

/*
 思路二： 直接使用二分查找。需要注意左右两个子序列边界的确定
 */

int search(int A[], int n, int target) {
    int low = 0, high = n - 1;
    int mid = (low + high) / 2;

    while( low <= high) {
        if(A[mid] == target)
            return mid;
        
        if(A[low] <= A[mid]) { // mid 位于前面的子序列的情况
            if(A[low] <= target && target < A[mid])
                high = mid - 1;
            else
                low = mid + 1;

        } else {            // mid 位于后面的子序列的情况
            if(target > A[mid] && target <= A[high])
                low = mid + 1;
            else
                high = mid - 1;
        }

        mid = (high + low) / 2;
    }

    return -1;
}
