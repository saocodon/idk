#include <iostream>
#include <string>
using namespace std;

void binary(int n, int num) {
	string s = "";
	while (num > 0) {
		if (n % 2 == 1)
			s += '1';
		else
			s += '0';
		num >>= 1;
	}
	for (int i = 0; i < n - s.length(); i++) cout << '0';
	for (int i = s.length() - 1; i >= 0; i--) cout << s[i];
	cout << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	bool c[(1 << n)];
	int num = 0, oldNum = -1;

	for (int cnt = 0; cnt < (1 << n); cnt++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (num & (1 << i)) {
					if (!c[(num & ~(1 << i))]) {
						num = num & ~(1 << i);
						c[num] = true;
						break;
					}
				} else {
					if (!c[(num | (1 << i))]) {
						num = num | (1 << i);
						c[num] = true;
						break;
					}
				}
			}
			if (num != oldNum) {
				oldNum = num;
				binary(n, num);
				break;
			}
		}
	}
}
