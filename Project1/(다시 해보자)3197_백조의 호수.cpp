#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1502

char graph[MAXSIZE][MAXSIZE];
char cboard[MAXSIZE][MAXSIZE];
int vis[MAXSIZE][MAXSIZE];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int r, c;
queue<pair<int, int>> LQ;		// ����
// ������ ã�°� �ƴ϶� ���� �ֺ��� ���� ã�°͵� �ϳ��� ����� �� �� ���� �Ͱ���.
queue<pair<int, int>> IQ;		// ����
int days;

bool MoveGoose() {
	queue<pair<int, int>> Q = LQ;
	Q.pop();

	for (int i = 0; i < r; i++) {
		fill(vis[i], vis[i] + MAXSIZE, 0);
	}

	while (!Q.empty()) {
		// ���� ��ġ �ʱ�ȭ
		auto cur = Q.front(); Q.pop();
		vis[cur.first][cur.second] = 1;

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (graph[nx][ny] == 'X' || vis[nx][ny] == 1) continue;

			if (graph[nx][ny] == 'L') return false;
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}
	return true;
}

void Melt() {
	while (!IQ.empty()) {
		auto cur = IQ.front(); IQ.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (graph[nx][ny] != 'X') {		// ǥ�鿡 ���� ������ ���
				cboard[cur.first][cur.second] = '.';
				break;
			}
		}
	}
}

void MeltSync() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			graph[i][j] = cboard[i][j];
			if (graph[i][j] == 'X') {
				IQ.push({ i,j });
			}
		}
	}
}
void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> graph[i][j];
			cboard[i][j] = graph[i][j];
			if (graph[i][j] == 'L') {
				LQ.push({ i,j });
			}
			else if (graph[i][j] == 'X') {
				IQ.push({ i,j });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	while (MoveGoose()) {
		Melt();
		MeltSync();
		days++;
	}
	cout << days;
}