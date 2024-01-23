#include<bits/stdc++.h>
using namespace std;

char building[1002][1002];
int fVis[1002][1002];		//  불 방문
int sVis[1002][1002];		// 상근이 방문

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	int w, h;

	while (t--) {
		cin >> w >> h;
		queue<pair<int, int>> Q;		// 불의 이동
		queue<pair<int, int>> sQ;		//상근이의 이동

		for (int i = 0; i < h; i++) {		// 방문 값 초기화
			fill(fVis[i], fVis[i] + w, -1);
			fill(sVis[i], sVis[i] + w, -1);
		}

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				cin >> building[i][j];
				if (building[i][j] == '*') {		// 불
					fVis[i][j] = 0;
					Q.push({ i,j });
				}
				else if (building[i][j] == '@') {		//  상근이
					sVis[i][j] = 0;
					sQ.push({ i,j });
					building[i][j] = '.';
				}
			}

		while (!Q.empty()) {			// Fire
			auto cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int ny = cur.first + dy[dir];
				int nx = cur.second + dx[dir];

				if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
				if (fVis[ny][nx] != -1 || building[ny][nx] != '.') continue;
				fVis[ny][nx] = fVis[cur.first][cur.second] + 1;
				Q.push({ ny,nx });
			}
		}

		bool IsEscape = false;

		while (!sQ.empty() && !IsEscape) {		//SangGuen
			auto cur = sQ.front(); sQ.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int ny = cur.first + dy[dir];
				int nx = cur.second + dx[dir];

				if (ny < 0 || nx < 0 || ny >= h || nx >= w) {
					IsEscape = true;
					cout << sVis[cur.first][cur.second] + 1 << '\n';
					break;
				}
				if (sVis[ny][nx] != -1)
					continue;
				else if (building[ny][nx] != '.')
					continue;
				else if ((sVis[cur.first][cur.second] + 1 >= fVis[ny][nx]) &&/**/ fVis[ny][nx] != -1)		// 불이 지나지 않았을때, 상근이도 못지나가는 알고리즘 이었음
					continue;
				sVis[ny][nx] = sVis[cur.first][cur.second] + 1;
				sQ.push({ ny,nx });
			}
		}

		if (!IsEscape) cout << "IMPOSSIBLE\n";
	}
}