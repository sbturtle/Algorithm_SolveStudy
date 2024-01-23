#include<bits/stdc++.h>
using namespace std;

int main() {
	queue<int> q;		// 현재 줄 서있는 곳
	stack<int> s;			//  한명씩만 설 수 있는 공간
	int n, r = 1;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		q.push(num);
	}

	while (true) {
		if (!q.empty() && r == q.front())		// Queue의 앞 사람의 순서인 경우
		{
			q.pop();
			r++;
		}
		else if (!s.empty() && r == s.top()) {		// Stack의 앞 사람의 순서인 경우
			s.pop();
			r++;
		}
		else if (!q.empty())		// 둘다 아닌경우
		{
			s.push(q.front());
			q.pop();
		}
		else    // Queue에 사람이 없고, Stack의 앞 사람의 순서가 아닌 경우
			break;
	}

	if (s.empty() && q.empty())		// 대기중인 사람이 없을 경우
		cout << "Nice";
	else
		cout << "Sad";


	return 0;
}