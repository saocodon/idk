#include <iostream>
#include <stack>
using namespace std;

int n = 2, x[16];
string steps = "";
stack<int> s;

void solve(int i);

int main() {
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	// solve
	/*
	int ans[16] = { 1 };
	for (int i = 1; i < 16; i++)
		ans[i] = (ans[i - 1] << 1);
	cout << ans[n] - 1 << '\n';*/
	while (1) {
		bool over = true;
		for (int k = 0; k < n; k++) {
			if (x[k] < 2) {
				over = false;
				break;
			}
		}
		if (over) break;
		solve(0);
	}
}

void solve(int i) {
	for (int j = 0; j < 3; j++) {
		cerr << "-- " << i << ' ' << j;
		// move disk i to j
		// the disk is already at j
		if (x[i] == j) {
			cerr << " false\n";
			continue;
		}
		// if there are smaller disks in j
		bool flag = true;
		for (int k = 0; k < i; k++) {
			if (x[k] == j) {
				flag = false;
				break;
			}
		}
		if (flag) {
			steps += to_string(x[i] + 1) + ' ' + to_string(j + 1) + '\n';
			cerr << " true\n" << steps;
			s.push(x[i]);
			x[i] = j;
			// check if game is solved
			bool over = true;
			for (int k = 0; k < n; k++) {
				if (x[k] < 2) {
					over = false;
					break;
				}
			}
			if (over) {
				cout << steps;
				break;
			}
			else {
				if (i < n - 1)
					solve(i + 1);
				// undo changes
				if (i < n - 1) {
					steps = steps.substr(0, steps.length() - 4);
					x[i] = s.top();
					s.pop();
				}
			}
		} else
			cerr << " false\n";
	}
}