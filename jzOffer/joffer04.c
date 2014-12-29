/*
 *题目：实现一个函数，把字符串中的每个空格替换成"%20"。
 		(此处假设在原字符串的空间足够大，要求在原字符串上做修改）
 *		e.g 输入"we are young"，则输出"we%20are%20young"。
 *		
 *思路：先扫描字符串统计出有多少个空格，然后算出替换后字符串的长度，从后向前地边移动字符边替换空格
 */

#include <string.h>
#define N 4096

void replaceBlank(char s[], int length) {
	if(s == NULL || length <= 0)
		return;
	int blankN = 0;
	
	char *p = s;
	while(*p != '\0') {
		if(*p == ' ')
			++blankN;
		++p;
	}
	if(blankN == 0)
		return;
	
	int newLength = length + 2 * blankN;
	
	int index = length;
	int newindex = newLength;

	while(index >= 0 && index < newindex) {
		if(s[index] == ' ') {
			s[newindex--] = '0';
			s[newindex--] = '2';
			s[newindex--] = '%';
		} else
			s[newindex--] = s[index];
		--index;
	}
	
}

int main() {
	
	char s1[N] = "we are young";
	replaceBlank(s1, 12);
	printf("%s\n", s1);

	char s2[N] = "baakdad";
	printf("%s\n", s2);
	
	return 0;
}
