#include <bits/stdc++.h>
using namespace std;
/*
// �ݷ�

//�Է�
1
7
2 3 4 5 3 1 2
//����
4 (3 -> 4, 4 -> 5, 5 -> 3)
�� ���� �߿� ó������ ���ư��� ���� �ڱ� �ڽ��� ��� ��� ���� ���� �ϼ��� �� �ֽ��ϴ�.
*/

int graph[100004];
int vis[100004];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int t;			// �׽�Ʈ Ƚ��
	cin >> t;

	while (t--) {
		queue<int> Q;
		int count = 0;
		int l;			// �л� ��
		cin >> l;

		for (int i = 1; i <= l; i++) {
			cin >> graph[i];
			if (graph[i] == i)
				vis[i] = i;
		}

		for (int i = 1; i <= l; i++)
		{
			if (vis[i] != 0 || graph[i] == i) continue;
			Q.push(graph[i]);

			vis[i] = i;
			bool c = true;
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();

				if (vis[cur] == i) {
					c = false;

					break;
				}
				if (vis[cur] != 0) continue;
				Q.push(graph[cur]);
				vis[cur] = i;
			}
			if (c) {
				while (!Q.empty()) {
					auto a = Q.front(); Q.pop();
					vis[a] = 0;
				}
				count++;
			}
		}	// l for

		cout << count << '\n';
	}	// t while

}
