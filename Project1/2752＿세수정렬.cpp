#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t[9];

	for (int i = 0; i < 9; i++)		cin >> t[i];

	for (int i = 0; i < 9; i++)
		for (int j = i; j < 9; j++) {
			int sum = 0;
			for (int num : t) {
				if (num == t[i] || num == t[j]) continue;
				sum += num;
			}

			if (sum == 100) {
				t[i] = 101;
				t[j] = 101;

				sort(t, t + 9);

				for (int k = 0; k < 7; k++)	 cout << t[k] << '\n';
				return 0;
			}
		}


}