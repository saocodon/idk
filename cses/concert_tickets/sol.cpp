#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
 
const int N = 2e5;
 
int h[N], n;
bool b[N];
 
int binary_search(int l, int r, int x) {
	int ans = -1;
	while (l <= r) {
		double t = (l + r) / 2.0;
		int m = round(t);
		//cerr << x << ' ' << m << ' ' << ans << '\n';
		// get the rightmost ticket (most expensive but doesn't exceed x)
		if (h[m] > x)
			r = m - 1;
		// khong the sap xep lai khach nen khong the lam theo cach giong bai
		// Apartments hay Ferris Wheel
		else if (h[m] < x) {
			// only if the next element is still not exceed x then we continue
			// searching
			if (h[m + 1] <= x)
				l = m + 1;
			else {
				if (b[m])
					r = m - 1;
				else
					l = m + 1;
			}

			if (!b[m])
				ans = m;
		}
		else if (h[m] == x) {
			if (b[m])
				r = m - 1;
			else {
				ans = m;
				l = m + 1;
			}
		}
	}
	//cerr << '\n';
	return ans;
}

// doing this because default UB is weird
int customLB(int l, int r, int x) {
	int ans = -1;
	while (l <= r) {
		double t = (l + r) / 2;
		int m = round(t);
		if (h[m] < x || h[m] == x) {
			l = m + 1;
			ans = m;
		}
		else if (h[m] > x)
			r = m - 1;
	}
	return ans;
}
 
int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);*/
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// input
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	// khong nen so duoc vi phu thuoc vao so tien cua khach hang
	sort(h, h + n);
	/*for (int i = 0; i < n; i++)
		cerr << h[i] << ' ';
	cerr << "\n\n";*/
	memset(b, 0, sizeof b);
	int L = 0, R = n - 1;
	for (int i = 0; i < m; i++) {
		//cerr << L << ' ' << R << '\n';
		int t;
		cin >> t;
		int Rl = customLB(L, R, t);
		//cerr << Rl << '\n';
		int p = binary_search(L, Rl, t);
		if (p == -1)
			cout << -1;
		else {
			b[p] = true;
			cout << h[p];
		}

		// shrinking search range
		while (b[R])
			R--;
		while (b[L])
			L++;

		cout << '\n';
	}
	/*for (int i = 0; i < n; i++)
		cerr << b[i] << ' ';*/
}