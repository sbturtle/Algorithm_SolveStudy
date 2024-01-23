#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;							// n은 시험장 수
	int b, c;						// b는 총감독관이 감시 가능한 수, c 부감독관이 감시 가능한 수

	long long result = 0;	// 값이 최대일 경우(1,000,000,000,000)
									// int 최대 범위인 2,147,483,647값을 넘어버리기 때문에 long long 사용
	vector<int> a;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		a.push_back(m);
	}

	cin >> b >> c;

	for (int i = 0; i < n; i++)
	{
		// 총감독관이 감시 가능한 수 제거
		a[i] -= b;
		result++;

		if (a[i] < 1)
			continue;

		// 부감독관이 감시 가능한 수 제거
		result += a[i] / c;
		a[i] % c ? result++ : result;
	}

	cout << result;

	return 0;
}