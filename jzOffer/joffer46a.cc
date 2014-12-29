#include <iostream>
using std::cout;
using std::endl;

class Temp {
public:
	Temp() {
		++N; 
		sum += N;
	}
	static void Reset() { N = 0; sum = 0;}
	static unsigned int GetSum() { return sum; }

private:
	static unsigned int N;
	static unsigned int sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::sum = 0;

unsigned int Sum_solution(unsigned int n) {
	Temp::Reset();

	Temp *a = new Temp[n];
	delete []a;
	a = NULL;
	return Temp::GetSum();
}

int main(void) {
	
	for(int i = 1; i < 6; i++)
		cout << i << " : " << Sum_solution(i) << endl;
	return 0;
}
