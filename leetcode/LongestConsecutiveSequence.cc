/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 
 */


/*
    思路：首先对num进行从小到大排序，然后从前向后地遍历num，统计可以组成连续数字的元素个数（注意：若出现重复的数字，则直接跳过
*/

#include <iostream>
using std::cout; 
#include <algorithm>
using std::sort;

#include <vector>
using std::vector;

int longestConsecutive(vector<int> &num) {
    if(num.empty() || num.size() == 1)
        return num.size();

    sort(num.begin(), num.end());
    int maxLength = 1, curLength = 1;
    auto pre = num.begin();
        for(auto cur = ++num.begin(); cur != num.end(); ++cur) {
            if(*cur == *pre) {
                 // 出现像等的元素直接pass
            } else {
                if((*cur - *pre) == 1) 
                    ++curLength;
                else {
                    if(curLength > maxLength)
                        maxLength = curLength;
                    curLength = 1;
                }
            }
            pre = cur;
        }
        if(curLength > maxLength)
            maxLength = curLength;
      
        return maxLength;
    }

int main() {

    vector<int> v{0, -1, 1, 1, 2, 6};
    int len = longestConsecutive(v);
    cout << "len: " << len;
}
