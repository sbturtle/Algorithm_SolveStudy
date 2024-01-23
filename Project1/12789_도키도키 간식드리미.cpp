#include<bits/stdc++.h>
using namespace std;

int main() {
	queue<int> q;		// ���� �� ���ִ� ��
	stack<int> s;			//  �Ѹ��� �� �� �ִ� ����
	int n, r = 1;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		q.push(num);
	}

	while (true) {
		if (!q.empty() && r == q.front())		// Queue�� �� ����� ������ ���
		{
			q.pop();
			r++;
		}
		else if (!s.empty() && r == s.top()) {		// Stack�� �� ����� ������ ���
			s.pop();
			r++;
		}
		else if (!q.empty())		// �Ѵ� �ƴѰ��
		{
			s.push(q.front());
			q.pop();
		}
		else    // Queue�� ����� ����, Stack�� �� ����� ������ �ƴ� ���
			break;
	}

	if (s.empty() && q.empty())		// ������� ����� ���� ���
		cout << "Nice";
	else
		cout << "Sad";


	return 0;
}