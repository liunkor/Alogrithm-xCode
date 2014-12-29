#include <stdio.h>

void reverse(char *beg, char *end);
void reverseSentence(char *str);

int main(void) {
//	char str[] = " I am a student.";   // 'char *str = "I am ..."' will bring up Segmentation fault (core dumped)

	char str[] = "student op";
	reverseSentence(str);
	printf("%s\n", str);

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

void reverseSentence(char *str) {
	if(str == NULL)
		return;

	char *beg = str;
	char *end = str;

	while(*end != '\0') 
		end++;
	end--;              //end points to the pos of before '\0'
	reverse(beg, end);  // reverse the whole sentence

	beg = end = str;
	while(*end != '\0') {   //reverse every word in the sentence
		while(*end != ' ' && *end != '\0')
			end++;
		end--;
		reverse(beg, end++);
		beg = ++end;
	}

}
