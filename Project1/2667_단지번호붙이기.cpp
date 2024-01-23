#include<bits/stdc++.h>
using namespace std;

string graph[30];
int graph[30][30];

int n;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<pair<int, int>> Q;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> graph[i];

	int size = 0;

	vector<int> sizes;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] != '1' || graph[i][j] != 0) continue;
			int dSize = 0;
			graph[i][j] = 1;
			Q.push({ i,j });
			size++;
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				dSize++;
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (graph[nx][ny] == '0' || graph[nx][ny] == 1) continue;
					graph[nx][ny] = 1;
					Q.push({ nx,ny });	
				}
			}		// while
			sizes.push_back(dSize);
		}
	}		// for
	sort(sizes.begin(), sizes.end());
	cout << size << '\n';

	for (auto num : sizes) {
	cout << num << '\n';

	}

}