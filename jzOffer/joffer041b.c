#include <stdio.h>

void printContinuousNumbers(int beg, int end);
void findContinuousSeqSum(int sum);

int main(void) {

	findContinuousSeqSum(10);
	findContinuousSeqSum(15);
	return 0;
}

void printContinuousNumbers(int beg, int end) {
	int i;
	for(i = beg; i <= end; i++)
		printf("%d  ", i);
	printf("\n");
}

void findContinuousSeqSum(int sum) {
	if(sum < 3)
		return ;
	
	int small = 1;
	int big = 2;
	int mid = (1 + sum) / 2;
	int curSum = small + big;

	while(small < mid) {
		if(curSum == sum)
			printContinuousNumbers(small, big);

		while(curSum > sum && small < mid) {
			curSum -= small;
			small++;

			if(curSum == sum)
				printContinuousNumbers(small, big);
		}
		big++;
		curSum += big;
	}

}
