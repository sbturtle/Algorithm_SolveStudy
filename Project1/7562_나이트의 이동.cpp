#include <bits/stdc++.h>
using namespace std;

int graph[302][302];
int graph[302][302];
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { 2,1,-1,-2,-2,-1,1,2 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	queue<pair<int, int>> Q;
	int t;
	cin >> t;
	while (t--) {
		while (!Q.empty()) Q.pop();

		int l;
		cin >> l;
		for (int i = 0; i < l; i++) {
			fill(graph[i], graph[i] + l, 0);
			fill(graph[i], graph[i] + l, -1);

		}
		int x, y;
		cin >> x >> y;
		graph[x][y] = 0;
		Q.push({ x,y });
		cin >> x >> y;
		graph[x][y] = 1;

		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			for (int i = 0; i < 8; i++)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
				if (graph[nx][ny] != -1) continue;
				graph[nx][ny] = graph[cur.first][cur.second] + 1;				
				Q.push({ nx, ny });
			}
		} // while

		cout << graph[x][y] << '\n';
	}
}