#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> r(n);
	for (int i = 0; i < n; i++) {
		cin >> r[i];
	}
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int x = 0;
	int y = 0;
	for (int i = 0; i < n; i++) {
		if (r[i] == 1 && b[i] == 0) {
			// count the number of 1s in vector 'r' which is a 0 in vector 'b'
			x++;
		}
		if (b[i] == 1 && r[i] == 0) {
			// count the number of 1s in vector 'b' which is a 0 in vector 'r'
			y++;
		}
	}
	// if 'x' is 0, then the answer is -1
	// otherwise:
	// (x * p) > y
	// p > (y / x), so p = ceil((y + 1) / x)
	cout << (x == 0 ? -1 : ((y + 1) % x == 0 ? (y + 1) / x : (y + 1) / x + 1)) << '\n';
	return 0;
}
