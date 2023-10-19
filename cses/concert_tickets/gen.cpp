#include <iostream>
#include <random>
using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> N(1, 10), H(1, 20);
	int n = N(gen), m = N(gen);
	cout << n << ' ' << m << '\n';
	for (int i = 0; i < n; i++)
		cout << H(gen) << ' ';
	cout << '\n';
	for (int i = 0; i < m; i++)
		cout << H(gen) << ' ';
	cout << '\n';
}