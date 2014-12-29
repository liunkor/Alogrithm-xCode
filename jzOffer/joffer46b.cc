#include <iostream>
using std::cout;
using std::endl;

class A;
A* Array[2];

class A {
public:
	virtual unsigned int sum(unsigned int n) {
		return 0;
	}
};

class B: public A {
public:
	virtual unsigned int sum(unsigned int n) {
		return Array[!!n]->sum(n - 1) + n;
	}
};

int Sum_solution2(int n) {
	
	A	a;
	B	b;
	Array[0] = &a;
	Array[1] = &b;
	int value = Array[1]->sum(n);

	return value;
}

int main(void) {

	for(int i = 0; i < 5; i++ ) 
		cout << i << ": " << Sum_solution2(i) << endl;
		
	return 0;

}

