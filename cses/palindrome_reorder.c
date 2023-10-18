#include <stdio.h>
#include <string.h>

const int N = 1e6 + 5;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("error.txt", "w", stderr);
	char solved = 0;
	char s[N];
	int a[26];
	memset(a, 0, sizeof a);
	fgets(s, N, stdin);
	int i = 0;
	while (*(s + i) != '\0') {
		a[*(s + i) - 65]++;
		i++;
	}
	int ones = 0; char c = '\0';
	char res[N]; int j = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i] % 2 == 1) {
			ones++;
			c = i + 65;
		}
		if (ones > 1) {
			printf("NO SOLUTION\n");
			solved = 1;
			break;
		}
		for (int k = 1; (2 * k <= a[i] && a[i] > 1); k++) {
			res[j] = i + 65;
			j++;
		}
	}
	//fprintf(stderr, "%d", a[0]);
	if (c != '\0') res[j++] = c;
	for (int i = 25; i >= 0; i--) {
		for (int k = 1; (2 * k <= a[i] && a[i] > 1); k++) {
			res[j] = i + 65;
			j++;
		}
	}
	if (solved == 0) printf("%s", res);
}