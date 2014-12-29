#include <stdio.h>

int add(int a, int b);

int main(void) {
	
	printf("%d\n", add(3, 12));
	printf("%d\n", add(20, 1));
	return 0;
}

int add(int a, int b) {
	int s1 = a ^ b;
	int s2 = (a & b) << 1;

	return s1 + s2;
}
