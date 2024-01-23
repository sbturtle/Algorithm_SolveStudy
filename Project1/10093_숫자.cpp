#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, m;
	cin >> a >> b;
	if (a == b) {
		cout << 0;
		return 0;
	}
	m = max(a, b);
	cout << abs(a - b) - 1 << '\n';
	for (long long i = min(a, b) + 1; i < m; i++)
		cout << i << ' ';
}