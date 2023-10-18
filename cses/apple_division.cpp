#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n, a[21];
long long f[21], s = 0;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
		f[i] = 1e11 + 1;
	}
	f[0] = s - 2 * a[0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			f[i] = min(min(abs(f[j] - 2 * a[i]), f[j]), f[i]);
		}
	}
	cout << f[n - 1];
}