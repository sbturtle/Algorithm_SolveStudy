#include <bits/stdc++.h>
using namespace std;
/*
// 반례

//입력
1
7
2 3 4 5 3 1 2
//정답
4 (3 -> 4, 4 -> 5, 5 -> 3)
팀 연결 중에 처음으로 돌아가는 경우랑 자기 자신을 찍는 경우 말고도 팀이 완성될 수 있습니다.
*/

int graph[100004];
int vis[100004];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int t;			// 테스트 횟수
	cin >> t;

	while (t--) {
		queue<int> Q;
		int count = 0;
		int l;			// 학생 수
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
