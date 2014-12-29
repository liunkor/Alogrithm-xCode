#include <stdio.h>
#include <stdlib.h>

int findNum(int * a[], int rows, int cols, int num);

int main(void) {

	int rows = 0, cols = 0;
	scanf("%d %d", &rows, &cols);
	if(rows < 1 || rows > 1000 || cols < 1 || cols > 1000) {
		printf("No");
		return -1;
	}
	int a[rows][cols];
	int num;
	scanf("%d", &num);
	if(num < 1 || num > 1000000)  {
		printf("No");
		return -1;
	}
	int i, j;
	int count = 0;

	for(i = 0; i < rows; i++) 
		for(j = 0; j < cols; j++)
			scanf("%d",&a[i][j]); 

	int found = findNum(a, rows, cols, num);
	if(found != 0) 
		printf("Yes");
	else
		printf("No");
	return 0;
}

int findNum(int * a[], int rows, int cols, int num) {

	int i, j;
	
	i = 0;
	j = cols - 1;
	while(i < rows && j >= 0) {
		if(num == a[i][j]) { 
			printf("%d ", a[i][j]);
			return 1;
		}
		else if(num < a[i][j]) {
			j--;
			printf("%d ", a[i][j]);
		}
		else{
			printf("%d ", a[i][j]);
			i++;
		}
	}
	return 0;
}

