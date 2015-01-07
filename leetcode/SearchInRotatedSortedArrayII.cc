/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
 */

class Solution {
public:
    bool search(int A[], int n, int target) {
        int low = 0, high = n - 1;
        int mid = (low + high) / 2;
        while( low <= high) {
            if(A[mid] == target)
                return true;
            
            if(A[low] < A[mid]) { // mid 位于前面一个子序列的情况
                if(A[low] <= target && target < A[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
    
            } else if(A[low] > A[mid]) {            // mid位于后面一个子序列的情况
                if(target > A[mid] && target <= A[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            } else    // A[low] == A[mid]
                ++low;  // 忽略掉第一个子序列中等于第二个子序列的元素
            mid = (low + high) / 2;
        }
        
        return false;
    
    }
};
