#include <iostream>
#include <string>
using namespace std;

int n;

void binary(int i) {
	string s = "";
	while (i > 0) {
		s += to_string(i % 2);
		i = (i >> 1);
	}
	for (int i = 0; i < n - s.length(); i++)
		cout << '0';
	for (int i = s.length() - 1; i >= 0; i--)
		cout << s[i];
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	// input
	cin >> n;
	// solve
	int num = 0;
	bool check[1 << 17];
	while (1) {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			// invert i-th bit
			if ((num & (1 << i)) != 0)
				num = (num & ~(1 << i));
			else
				num = (num | (1 << i));
			// check if exists
			if (check[num]) {
				// undo the changes
				if ((num & (1 << i)) != 0)
					num = (num & ~(1 << i));
				else
					num = (num | (1 << i));
			} else {
				check[num] = true;
				binary(num);
				flag = true;
				break;
			}
		}
		if (!flag) break;
	}
}