#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int sz[200000], c[200000], n, k;
bool used[200000];

bool binarySearch(int x) {
	int l = 0, r = n - 1, ans = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (sz[m] >= x - k && sz[m] <= x + k) {
			if (!used[m]) {
				ans = m;
				r = m - 1;
			} else
				l = m + 1;
		}
		else if (sz[m] > x - k)
			r = m - 1;
		else if (sz[m] < x + k)
			l = m + 1;
	}
	if (ans != -1) {
		used[ans] = true;
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// input
	int m, ans = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> sz[i];
	// solve
	sort(sz, sz + n);
	for (int i = 0; i < m; i++)
		cin >> c[i];
	sort(c, c + m);
	memset(used, 0, sizeof used);
	for (int i = 0; i < m; i++) {
		if (binarySearch(c[i]))
			ans++;
	}
	cout << ans;
}