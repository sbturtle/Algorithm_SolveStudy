#include<bits/stdc++.h>
using namespace std;

int func(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) return 1;

	return func(n - 1) + func(n - 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	cout << func(n);
}