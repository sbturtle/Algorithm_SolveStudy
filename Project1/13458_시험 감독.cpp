#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;							// n�� ������ ��
	int b, c;						// b�� �Ѱ������� ���� ������ ��, c �ΰ������� ���� ������ ��

	long long result = 0;	// ���� �ִ��� ���(1,000,000,000,000)
									// int �ִ� ������ 2,147,483,647���� �Ѿ������ ������ long long ���
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
		// �Ѱ������� ���� ������ �� ����
		a[i] -= b;
		result++;

		if (a[i] < 1)
			continue;

		// �ΰ������� ���� ������ �� ����
		result += a[i] / c;
		a[i] % c ? result++ : result;
	}

	cout << result;

	return 0;
}