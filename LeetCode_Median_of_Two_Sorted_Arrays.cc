/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int i = 0, j = 0;
	int median = n + m;
	double first = 0.0;
	double second = 0.0;
	if(median < 2) {           //注意：数组A和数组B的长度之后小于2的处理
		if(m == 0 && n == 0)
			return 0.0;
		if(m == 1) 
			return A[0];
		else
			return B[0];
	}

	while((i + j) <= (median / 2)) {
		first = second;
		if(i >= m) {
			second = B[j];      //注意：要先将B[j]赋予second，再j++
			j++;
		
		} else if(j >= n) {
			second = A[i];
			i++;
			
		} else if(A[i] <= B[j]) {
			second = A[i];
			i++;
		} else {
			second = B[j];
			j++;
		}
	}

	if(median % 2) {     // m+n奇数时，中位数为第（m+n)/2 个
		return second;
	}
	else {             // m+n偶数时，中位数为第 n/2 和 第 n/2 -1 的两数的平均数
		return (first + second) / 2.0;
	}
	
    }
};
