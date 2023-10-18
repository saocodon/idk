#include <stdio.h>

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("error.txt", "w", stderr);
	int t, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
		// solution
		if (a == 0 && b == 0) { printf("YES\n"); continue; }
		if (a == 0 || b == 0) { printf("NO\n"); continue; }
		if (a > b * 2 || b > a * 2) { printf("NO\n"); continue; }
		int am = a % 3, bm = b % 3;
		if (am == 0 && bm == 0) { printf("YES\n"); continue; }
		if (am == 0 && bm == 1) { printf("NO\n"); continue; }
		if (am == 0 && bm == 2) { printf("NO\n"); continue; }
		if (am == 1 && bm == 0) { printf("NO\n"); continue; }
		if (am == 1 && bm == 1) { printf("NO\n"); continue; }
		if (am == 1 && bm == 2) { printf("YES\n"); continue; }
		if (am == 2 && bm == 0) { printf("NO\n"); continue; }
		if (am == 2 && bm == 1) { printf("YES\n"); continue; }
		if (am == 2 && bm == 2) { printf("NO\n"); continue; }
	}
}