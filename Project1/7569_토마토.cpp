#include <bits/stdc++.h>
using namespace std;

int graph[102][102][102];
int graph[102][102][102];
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int n, m, h;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n >> h;
	queue<tuple<int, int, int>> Q;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
				fill(graph[i][j], graph[i][j] + m, -1);

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				cin >> graph[i][j][k];
				if (graph[i][j][k] == 1)
				{
					graph[i][j][k] = 0;
					Q.push({ i,j,k });
				}
			}

	int result = 0;

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		result = graph[get<0>(cur)][get<1>(cur)][get<2>(cur)];
		for (int i = 0; i < 6; i++) {
			int nz = get<0>(cur) + dz[i];
			int ny = get<1>(cur) + dy[i];
			int nx = get<2>(cur) + dx[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
			if (graph[nz][ny][nx] != -1 || graph[nz][ny][nx] != 0) continue;

			graph[nz][ny][nx] = graph[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			Q.push({ nz,ny,nx });
		}
	}

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				if (graph[i][j][k] == 0 && graph[i][j][k] == -1) {
					result = -1;
				}
			}

	cout << result;

}