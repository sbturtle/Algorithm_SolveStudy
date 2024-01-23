#include<bits/stdc++.h>
using namespace std;

string func(int n) {
	if (n == 0)	return "-";

	string result = "";
	int num = (int)pow(3, n - 1);

	for (int i = 0; i < num; i++) {
		result += " ";
	}

	return func(n - 1) + result + func(n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	while (cin >> n) {
		cout << func(n) << '\n';
	}

}