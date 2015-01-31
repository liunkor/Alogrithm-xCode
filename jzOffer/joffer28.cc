/*
 * 题目： 输入一个字符串，输出该字符串打所有排列
 思路：
    第一步：总体可以把字符串分为两部分：字符串的第一个字符和第一个字符以后的所有字符。将第一个字符与后面每个字符交换一次。
    第二步：在第一个的每次交换后，固定第一个字符来求后面所有字符的排列（一个递归过程）。每次递归后要换回与第一个字符交换的字符

 */

#include <iostream>
using std::cout; using std::endl;

void permutation(char*, char*);
void permutation(char *str) {
    if(str == NULL)
        return;
    permutation(str, str);
}

void permutation(char *str, char *begin) { // 注意begin从首字符位置开始
    if(*begin == '\0')
        cout << str << endl;
    else {
        for(char *ch = begin; *ch != '\0'; ++ch) {  
            char temp = *ch;             // 首字符与首字符后面的字符交换
            *ch = *begin;
            *begin = temp;

            permutation(str, begin + 1);   // 固定交换后的新首字符，递归（去对后面的字符进行全排）

            temp = *begin;          //每次递归后还原首字符
            *begin = *ch;
            *ch = temp;
        }
    }
}

int main() {
    char str[] = "abc";
    permutation(str);

    char str1[] = "";
    permutation(str1);
    char str2[] = "a";
    permutation(str2);
    char str3[] = "ab";
    permutation(str3);

}
