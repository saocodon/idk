#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char id[8];
int n = 0, x[8], idc[8], ans = 0;
string s, temp = "";

void backtracking(int i);

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	// input
	cin >> s;
	// solve
	/// convert to numbers
	sort(s.begin(), s.end());
	//// init
	id[0] = s[0];
	x[0] = 0;
	idc[0] = 1;
	//// convert
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != s[i - 1]) {
			n++;
			id[n] = s[i];
		}
		x[i] = n;
		idc[n]++;
	}
	//// backtracking
	backtracking(0);
	cout << ans << '\n' << temp;
}

void backtracking(int i) {
	for (int j = 0; j <= n; j++) {
		if (idc[j] > 0) {
			x[i] = j;
			idc[j]--;
			if (i == s.length() - 1) {
				ans++;
				for (int k = 0; k <= i; k++)
					temp += id[x[k]];
				temp += '\n';
				idc[j]++;
			} else {
				backtracking(i + 1);
				idc[j]++;
			}
		}
	}
}