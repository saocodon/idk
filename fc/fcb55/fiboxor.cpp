#include <iostream>
using namespace std;

int main() {
	int a, b, n;
	cin >> a >> b >> n;
	n %= 3;
	switch (n) {
		case 0:
			cout << a;
			break;
		case 1:
			cout << b;
			break;
		case 2:
			cout << (a ^ b);
			break;
	}
}