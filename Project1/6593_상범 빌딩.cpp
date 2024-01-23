#include<bits/stdc++.h>
using namespace std;

int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

char graph[30][30][30] = {};
int graph[30][30][30] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (true) {

		queue<tuple<int, int, int>> Q;
		int l, r, c;
		cin >> l >> c >> r;
		if (l == 0 && c == 0 && r == 0) break;

		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				fill(graph[i][j], graph[i][j] + 30, 0);
				fill(graph[i][j], graph[i][j] + 30, 0);
			}
		}

		tuple<int, int, int> escape;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < c; j++) {
				for (int k = 0; k < r; k++) {
					cin >> graph[i][j][k];
					if (graph[i][j][k] == 'S') {
						graph[i][j][k] = 1;
						Q.push({ i,j,k });
					}
					else if (graph[i][j][k] == 'E') {
						escape = { i,j,k };
						graph[i][j][k] = '.';
					}
				}
			}
		}

		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 6; dir++)
			{
				int nz = get<0>(cur) + dz[dir];
				int ny = get<1>(cur) + dy[dir];
				int nx = get<2>(cur) + dx[dir];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;

				if (graph[nz][ny][nx] != '.' || graph[nz][ny][nx] != 0) continue;

				graph[nz][ny][nx] = graph[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;

				Q.push({ nz,ny,nx });
			}
		}		// while

		if (graph[get<0>(escape)][get<1>(escape)][get<2>(escape)] == 0) cout << "Trapped!" << '\n';
		else cout << "Escaped in " << graph[get<0>(escape)][get<1>(escape)][get<2>(escape)] - 1 << " minute(s).\n";

	}		// while
}