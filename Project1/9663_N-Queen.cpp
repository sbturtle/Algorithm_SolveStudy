#include <bits/stdc++.h>
using namespace std;

int n;

bool isUsed1[40];
bool isUsed2[40];
bool isUsed3[40];
int cnt;

void func(int cur) {
	if (cur == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isUsed1[i] || isUsed2[i + cur] || isUsed3[cur - i + n - 1])
			continue;

		isUsed1[i] = true;
		isUsed2[i + cur] = true;
		isUsed3[cur - i + n - 1] = true;
		func(cur + 1);
		isUsed1[i] = false;
		isUsed2[i + cur] = false;
		isUsed3[cur - i + n - 1] = false;


	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	func(0);

	cout << cnt;
}