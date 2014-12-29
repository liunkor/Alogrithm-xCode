/*
Remove Duplicates from Sorted Array

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

 */

/*
 *思路：类似 Remove Duplicates from Sorted Array的方法，只是多加了一个flag来标记当前所要处理的元素是否已经出现过2次，若是，则直接跳过。

 */

int removeDuplicates(int A[], int n) {
        if(A == NULL || n == 0)
            return 0;
        if(A != NULL && n == 1) 
            return 1;
        
        int pre = 0, curr = 1;
        bool firstTwo = true;
        while(curr < n) {
            
            if(A[pre] != A[curr]) {
                A[++pre] = A[curr];
                firstTwo = true;
            } else {
                if(firstTwo) {
                    A[++pre] = A[curr];
                    firstTwo = false;
                }
            }
            ++curr;
        }
        
        return pre + 1;
    }
