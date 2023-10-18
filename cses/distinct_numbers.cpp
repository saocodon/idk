#include <iostream>
#include <algorithm>
using namespace std;

int a[200000];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	// pp nen so
	sort(a, a + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > a[i - 1])
			cnt++;
	}
	cout << cnt;
}