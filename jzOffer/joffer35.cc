/*
 *  查找字符串中第一个只出现一次的字符
 *
 */
#include <iostream>
using std::cout; using std::endl;

#include <map>
using std::map;

char findFirstCharOccurOnce(char * str) { // 使用map，key为字符,value为该字符出现的次数
    if(str == NULL)
        return '0';

    char *p = str;
    map<char, int> m;
    
    while(*p != '\0') 
        ++m[(*p++)];

    auto it = m.begin();
    while(it != m.end()) {
        if(it->second == 1)
            return it->first;
        ++it;
    }
    return '\0';
}
char findFirstCharOccurOnce2(char * str) {   // 用一个256长度的数组做为哈希表，先后扫描字符串2次来找出只出现一次的字符
    if(str == NULL)
        return '\0';
    const int hashSize = 256;
    unsigned int hashTable[hashSize];
    for(int i = 0; i < hashSize; ++i)
        hashTable[i] = 0;    

    char *p = str;
    while(*p != '\0') {
        ++hashTable[*p];
        ++p;
    }
    
    p = str;
    while(*p != '\0') {
        if(hashTable[*p] == 1)
            return *p;
        ++p;
    }

    return '\0';
}
int main() {
    char str[] = "abaccdeff";
    cout << findFirstCharOccurOnce(str) << endl;

    char str2[] = "abbaccdkeff";
    cout << findFirstCharOccurOnce2(str2) << endl;

    char str3[] = "";
    cout << findFirstCharOccurOnce2(str3) << endl;
}
