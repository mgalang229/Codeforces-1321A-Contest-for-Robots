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
	vector<bool> visited(n, false);
	// mark the indices wherein both vector 'r' and 'b' have 1
	for (int i = 0; i < n; i++) {
		if (r[i] == 1 && b[i] == 1) {
			visited[i] = true;
		}
	}
	int ans = -1;
	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j < n; j++) {
			if (r[j] > 0) {
				// if the current element is equal to 1, then change it to the value of 'i'
				r[j] = i;
			}
		}
		for (int j = 0; j < n; j++) {
			// if the current index is marked, then change it to the value of 'i'
			if (visited[j]) {
				b[j] = i;
			}
		}
		// check if the sum of vector 'r' is STRICTLY greater than the sum of vector 'b'
		if (accumulate(r.begin(), r.end(), 0) > accumulate(b.begin(), b.end(), 0)) {
			// store the current 'i' value
			ans = i;
			// break the loop (since we only need the minimum)
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}
