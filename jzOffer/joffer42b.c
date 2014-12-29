#include <stdio.h>

char * leftTurnString(char * str, unsigned int n);

int main(void) {

	char str[] = "abcdefgh";
	char *pstr = leftTurnString(str, 5);
	if(pstr == NULL)
		return -1;

	printf("%s\n", pstr);

	return 0;

}

char * leftTurnString(char * str, unsigned int n) {
	if(str == NULL || n == 0)
		return str;
	
	char *beg = str;
	char *end = str;
	int cNum = 0;
	
	while(*end++ != '\0') 
		cNum++;
	if(cNum < n)
		return NULL;
	if(cNum > 0)
		end--;
	
	while(n-- > 0)
		*end++ = *beg++;
	
	*end = '\0';
	return beg;
}
