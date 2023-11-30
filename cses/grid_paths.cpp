#include <iostream>
using namespace std;

long long f[7][7];
string s;

int main() {
	cin >> s;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++)
			f[i][j] = 0;
	}
	f[0][0] = 1;
	for (int i = 0; i < 7; i++) {
		bool rtl = false;
		for (int j = 0; j < 7; j++) {
			if (s[i * 7 + j] == 'L') {
				rtl = true;
				break;
			}
		}
		if (i == 6) rtl = true;
		// --- calculate f[i][j] ---
		if (rtl) {
			for (int j = 6; j >= 0; j--) {
				if (i == 0 && j == 0) continue;

				if (j < 6)
					f[i][j] = f[i][j + 1];
				if (j < 5 && i == 0)
					f[i][j] += f[i][j + 2];

				if (s[i * 7 + 7 - j] == 'D') {
					int t = max(7 - i, 7 - j) * max(7 - i, 7 - j) - ((7 - i) * 7 + 7 - j);
					if (t == 7 - i || t == 7 - j)
						f[i][j] = ((i > 0) ? f[i - 1][j] : 0);
				}
				if (s[i * 7 + 7 - j] == '?') {
					f[i][j] += ((i > 0) ? f[i - 1][j] : 0);
					if (i < 6 && j < 6)
						f[i][j] -= f[i + 1][j + 1];
				}
				// else = L
			}
		} else {
			for (int j = 0; j < 7; j++) {
				if (i == 0 && j == 0) continue;

				if (j > 0)
					f[i][j] = f[i][j - 1];
				if (j > 1 && i == 0)
					f[i][j] += f[i][j - 2];

				if (s[i * 7 + j] == 'D') {
					int t = max(i, j) * max(i, j) - i * 7 + j;
					if (t == i || t == j)
						f[i][j] = ((i > 0) ? f[i - 1][j] : 0);
				}
				if (s[i * 7 + j] == '?') {
					f[i][j] += ((i > 0) ? f[i - 1][j] : 0);
					if (i > 1 && j > 1)
						f[i][j] -= f[i - 1][j - 1];
				}
				// else = R
			}
		}
	}
	cout << f[6][0];
}
