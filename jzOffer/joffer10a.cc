#include <iostream>
using std::endl; using std::cout;

int numOfOne(int n) {
    int num = 0;
    if(n == 0)
        return 0;

    while(n > 0 || n < 0) {
        if(n & 0x80000000)
            ++num;
        n = n << 1;
    }
    return num;
}

int main() {
    cout << "6: " << numOfOne(6) << endl;
    cout << "2: " << numOfOne(2) << endl;
    cout << "15: " << numOfOne(15) << endl;
}
