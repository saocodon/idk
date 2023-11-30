#include <iostream>
using namespace std;

long long ans = 0, S = 0, S1 = 0;
bool c[20];
int n, p[20];

void Try(int i) {
	for (int j = 0; j < n; j++) {
		if (!c[j] && i < n) {
			c[j] = true;
			S1 += p[j];
			if (abs(S - 2 * S1) < ans) {
				ans = abs(S - 2 * S1);
			} else {
				Try(i + 1);
				c[j] = false;
				S1 -= p[j];	
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		S += p[i];
	}
	ans = S;
	Try(0);
	cout << ans;
}
