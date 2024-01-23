#include <bits/stdc++.h>
using namespace std;

int graph[304][304];
int cBoard[304][304];
int vis[304][304];
int eVis[304][304];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n, m; // 세로, 가로

int year;
queue<pair<int, int>> Q;

/*
1. 값을 입력 받고
2. 빙산이 몇개인지 확인
	2-1. 빙산이 1개일 경우 3으로 이동
	2-2. 빙산이 2개이상이면 해당년도 반환
	2-3. 빙산이 0개면 0 반환
3. 빙산 녹이기
	※ 빙산을 차례차례 녹이면 오류 발생가능. 따라서 녹기 직전의 정보를 토대로 녹여야 함.
*/


void Init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] != 0)
				cBoard[i][j] = graph[i][j];
		}
	}
}

bool Explore() {		// 빙산 개수 체크
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (eVis[i][j] != 0 || graph[i][j] == 0) continue;
			Q.push({ i,j });
			num++;
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				if (eVis[cur.first][cur.second] < 0)
					continue;

				for (int dir = 0; dir < 4; dir++)
				{
					if (graph[cur.first][cur.second] == 0) continue;

					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (graph[nx][ny] == 0 || eVis[nx][ny] != 0) continue;
					eVis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}		// while 
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			eVis[i][j] = 0;

	if (num == 1) {
		return true;
	}
	else if (num > 1) {
		cout << year;
		return false;
	}
	else {
		cout << 0;
		return false;
	}
}

void Melt() {		//  빙산 녹이기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] != 0 || cBoard[i][j] == 0) continue;
			Q.push({ i,j });

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				if (vis[cur.first][cur.second] < 0)
					continue;

				for (int dir = 0; dir < 4; dir++)
				{
					if (graph[cur.first][cur.second] == 0) continue;

					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (cBoard[nx][ny] != 0 || vis[nx][ny] != 0) continue;
					vis[cur.first][cur.second] = 1;
					graph[cur.first][cur.second]--;
				}
			}		// while 
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vis[i][j] = 0;
			cBoard[i][j] = graph[i][j];
		}
	}

	year++;
}

void Solve() {
	while (Explore()) {
		Melt();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Init();
	Solve();
}