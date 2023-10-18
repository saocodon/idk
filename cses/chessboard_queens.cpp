#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

bool a[8][8];
int x[8]; // row = index, column = value
int ans = 0;

void backtracking(int i);

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// input
	memset(a, 0, sizeof a);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char t; cin >> t;
			if (t == '*')
				a[i][j] = true;
		}
	}
	// solve
	memset(x, -1, sizeof x);
	backtracking(0);
	cout << ans;
}

void backtracking(int i) {
	for (int j = 0; j < 8; j++) {
		bool flag = true;
		// check if [i,j] has been kept by prior queens
		if (a[i][j]) flag = false;
		for (int k = 0; k < i; k++) {
			if (x[k] == j || abs(k - i) == abs(x[k] - j)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			x[i] = j;
			if (i == 7) {
				ans++;
			}
			else {
				backtracking(i + 1);
				x[i] = -1;
			}
		}
	}
}