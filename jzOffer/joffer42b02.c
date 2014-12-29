#include <stdio.h>

void reverse(char *beg, char *end);
char *leftTurnString(char *str, int n);

int main(void) {

	char str[] = "abcdefg";
	char *pstr = leftTurnString(str, 5);

	if(pstr != NULL)
		printf("%s", pstr);
	else 
		printf("NULL");
	return 0;
}

void reverse(char *beg, char *end) {
	if(beg == NULL || end == NULL) 
		return;

	char tmp;
	while(beg < end) {
		tmp = *beg;
		*beg = *end;
		*end = tmp;
		beg++;
		end--;
	}
}

char * leftTurnString(char *str, int n) {
	if(str == NULL || n <= 0)
		return str;
	
	char *beg = str;
	char *end = str;
	char *mid;
	int cNum = 0;
	while(*end != '\0') {  // can't be while(*end ++ != '\0') 
		cNum++;
		end++;
	}
	if(cNum < n)
		return NULL;
	if(cNum > 0)
		end--;
	reverse(beg, end);   // reverse the whole string
	
	mid = end;
	while((--n > 0) && (mid > beg))
		mid--;
	reverse(mid, end);   //reverse the n character part of string

	if(beg < mid)
		mid--;
	reverse(beg, mid);   // reverse the other part of string

	return str;
}
