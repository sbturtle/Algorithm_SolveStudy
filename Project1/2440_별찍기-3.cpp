#include<bits/stdc++.h>
using namespace std;

void star(int op, int ed)
{
	if (op >= ed) return;
	cout << '*';
	star(op + 1, ed);
}

void recursion(int n)
{
	if (n < 0) return;
	star(0, n);
	cout << '\n';
	recursion(n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	recursion(n);
}