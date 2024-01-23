//1. 공기랑 맞닿아있는 치즈 확인
// > 0.0 : 무조건 공기
//	0.0을 넣어서  graph[my] [[nx]== 1 즉 치즈면 공기랑 바로 맞닿아있는 치즈이ㅏ기 때문에  checkCheesebetweenAir[ny][nx] == true
//	isAir > 공기랑 맞닿아이쓴ㄴ 치즈인지 아닌지 판단 배열
//	cheese > 치즈 배열 > ㅇ얘를 녹여야함.
//
//	2. BFS 돌기
//	if (cheese[y][x] == 1 && isAir[ny][nx])  녹이기;
//
//배열은 총 2개 있어야 함.
#include<bits/stdc++.h>
using namespace std;

int n, m;
bool graph[101][101];
bool sgraph[101][101];

int agraph[101][101];		//외부공기

int vis[101][101];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int cnt;
queue<pair<int, int>> Q;

bool asd(int nx, int ny) {
	return nx < 0 || nx >= n || ny < 0 || ny >= m;
}

bool Check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sgraph[i][j] = graph[i][j];
			if (sgraph[i][j])
				Q.push({ i,j });
		}
	}

	return !Q.empty();
}
void IsInAir() {
	memset(agraph, -1, sizeof(agraph));
	queue<pair<int, int>> Q1;
	Q1.push({ 0,0 });
	while (!Q1.empty()) {
		auto cur = Q1.front(); Q1.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (asd(nx, ny)) continue;
			

			Q1.push({ nx,ny });
			agraph[nx][ny] = 1;
		}
	}
}

void BFS() {
	memset(vis, 0, sizeof(vis));

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (asd(nx, ny)) continue;
			if (sgraph[nx][ny] == 1 && agraph[nx][ny] != 1) continue;
			if (++vis[nx][ny] > 1)
				graph[nx][ny] = 0;
		}
	}
	cnt++;
}

void Solve() {
	if (Check()) {
		// 외부공기 세팅
		IsInAir();
		// 치즈마다 주변 외부공기에 대한 값 받아서 지울까?
		BFS();
	}
}

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	Solve();
	cout << cnt;
	return 0;
}