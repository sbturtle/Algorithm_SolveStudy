#include<bits/stdc++.h>
using namespace std;

long long recursion(int n) {
	if (n <= 1) return 1;
	return (long long)n * recursion(n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	cout << recursion(n);
}