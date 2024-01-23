#include <bits/stdc++.h>
using namespace std;

int graph[304][304];
int cBoard[304][304];
int vis[304][304];
int eVis[304][304];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n, m; // ����, ����

int year;
queue<pair<int, int>> Q;

/*
1. ���� �Է� �ް�
2. ������ ����� Ȯ��
	2-1. ������ 1���� ��� 3���� �̵�
	2-2. ������ 2���̻��̸� �ش�⵵ ��ȯ
	2-3. ������ 0���� 0 ��ȯ
3. ���� ���̱�
	�� ������ �������� ���̸� ���� �߻�����. ���� ��� ������ ������ ���� �쿩�� ��.
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

bool Explore() {		// ���� ���� üũ
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

void Melt() {		//  ���� ���̱�
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