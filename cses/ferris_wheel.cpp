#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool u[200000];
int w[200000], n;

int binarySearch(int l, int r, int x) {
	int res = -1;
	while (l <= r) {
		double t = (l + r) / 2.0;
		int m = round(t);
		if (w[m] == x) {
			// take the rightmost element equals x/smaller than x
			// (as near x as possible)
			if (!u[m]) {
				res = m;
				l = m + 1;
			}
			else
				r = m - 1;
		}
		else if (w[m] > x)
			r = m - 1;
		else if (w[m] < x) {
			res = m;
			l = m + 1;
		}
	}
	if (!u[res])
		return res;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// input
	int x, ans = 0, nr;
	cin >> n >> x;
	nr = n;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	sort(w, w + n);
	int li = n; // last iteration
	for (int i = 0; i < n; i++) {
		if (!u[i]) {
			u[i] = true;
			int id = binarySearch(i, li - 1, x - w[i]);
			if (id != -1) {
				nr -= 2;
				ans++;
				u[id] = true;
				li = id;
			}
		}
	}
	cout << ans + nr;
}