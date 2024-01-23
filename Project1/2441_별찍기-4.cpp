#include<bits/stdc++.h>
using namespace std;

int n;

void star(int op, int ed)
{
	if (op >= ed) return;
	cout << '*';

	star(op + 1, ed);
}

void space(int n1)
{
	if (n1 >= n) return;
	cout << ' ';

	space(n1 + 1);
}

void recursion(int n1)
{
	if (n1 <= 0) return;

	space(n1);
	star(0, n1);
	cout << '\n';
	recursion(n1 - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int a = n;
	recursion(a);

}