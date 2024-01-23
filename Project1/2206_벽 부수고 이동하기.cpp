#include <bits/stdc++.h>

using namespace std;

string graph[1001];
int vis[1001][1001][2];
int n, m, k = 1;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs() {
	queue<pair<pair<int, int>, int>> q;

	q.push({ {0, 0 }, 0 });
	vis[0][0][0] = 0;

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cost = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			//기저조건
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (graph[ny][nx] == '1') {
				if (cost >= k) continue;

				if (vis[ny][nx][cost] > vis[ny][nx][cost + 1]) {
					q.push({ {ny, nx}, cost + 1 });
				}
			}
			if (graph[ny][nx] == '0') {
				q.push({ {ny, nx}, cost });
			}
		}
	}

	return min(vis[n][m][0], vis[n][m][1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(vis, -1, sizeof(vis));
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> graph[i];
	}

	cout << bfs();
}