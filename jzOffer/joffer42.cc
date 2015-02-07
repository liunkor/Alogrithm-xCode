/*
 *  输入一个英文句子，翻转句子中单词的顺序，但是单词内字符的顺序不变
 *  e.g I am a student. -----> student. a am I
 *
 *  思路：两次翻转字符串
 */
#include <iostream>
using std::cout; using std::endl;

void reverseStr(char *begin, char *end) {
    if(begin == NULL || end == NULL)
        return;

    while(begin < end) {
        char tmp = *begin;
        *begin = *end;
        *end = tmp;
        ++begin;
        --end;
    }
}   

void reverseWordInString(char *str) {
    if(str == NULL)
        return;
    char *p = str;
    int len = 0;
    while(*p != '\0') {
        ++len;
        ++p;
    }
    reverseStr(str, p - 1);
    
    char *begin = str;
    char *end = str;
    p = str;
    while(*p != '\0') {
        if(*p == ' ') {
            end = p - 1;
            reverseStr(begin, end);
            begin = p + 1;
        }
        ++p;
        if(*p == '\0') {
            reverseStr(begin, p - 1);
        }
    }
}

int main() {
    char str[] = "I am a student.";
    reverseWordInString(str);
    cout << str << endl;
}
