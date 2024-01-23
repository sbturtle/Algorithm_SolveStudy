//1. ����� �´���ִ� ġ�� Ȯ��
// > 0.0 : ������ ����
//	0.0�� �־  graph[my] [[nx]== 1 �� ġ��� ����� �ٷ� �´���ִ� ġ���̤��� ������  checkCheesebetweenAir[ny][nx] == true
//	isAir > ����� �´���̾��� ġ������ �ƴ��� �Ǵ� �迭
//	cheese > ġ�� �迭 > ���긦 �쿩����.
//
//	2. BFS ����
//	if (cheese[y][x] == 1 && isAir[ny][nx])  ���̱�;
//
//�迭�� �� 2�� �־�� ��.
#include<bits/stdc++.h>
using namespace std;

int n, m;
bool graph[101][101];
bool sgraph[101][101];

int agraph[101][101];		//�ܺΰ���

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
		// �ܺΰ��� ����
		IsInAir();
		// ġ��� �ֺ� �ܺΰ��⿡ ���� �� �޾Ƽ� �����?
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