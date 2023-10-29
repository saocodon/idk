#include <iostream>
#include <cstring>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, d[100001];
		memset(d, -1, sizeof d);
		cin >> n;
		bool solved = false;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			if (d[t] == -1)
				d[t] = i;
			else {
				if (i - d[t] > 1) {
					cout << "YES\n";
					solved = true;
					break;
				}
			}
		}
		if (!solved)
			cout << "NO\n";
	}
}