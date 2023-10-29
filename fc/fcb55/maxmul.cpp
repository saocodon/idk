#include <iostream>
using namespace std;

const int N = 1e5 + 1;
const int mod = 1e9 + 7;

struct segTree {
	int n, a[N];
	long long tree[4 * N];

	void buildTree(int root, int l, int r) {
		if (l == r) {
			tree[root] = a[l];
			return;
		}
		int m = (l + r) / 2;
		buildTree(root * 2, l, m);
		buildTree(root * 2 + 1, m + 1, r);
		tree[root] = (tree[root * 2] * tree[root * 2 + 1]) % mod;
	}

	long long get(int root, int l, int r, int u, int k) {
		// khong thuoc mien quan ly
		if (u > r || u + k - 1 < l) return 1;
		// co thuoc mien quan ly ([l,r] nam trong [u,u+k-1])
		if (l >= u && r <= u + k - 1) return tree[root];
		int m = (l + r) / 2;
		return (get(root * 2, l, m, u, k) * get(root * 2 + 1, m + 1, r, u, k)) % mod;
	}
};

int main() {
	segTree st;
	cin >> st.n;
	for (int i = 1; i <= st.n; i++)
		cin >> st.a[i];
	st.buildTree(1, 1, st.n);
	int q; cin >> q;
	while (q--) {
		int u, k; cin >> u >> k;
		cout << st.get(1, 1, st.n, u, k) << '\n';
	}
}