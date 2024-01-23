#include <bits/stdc++.h>
using namespace std;

int graph[1002][1002];
int graph[1002][1002];

int n, m;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<pair<int, int>> Q;
	int t;

	vector<int> sizes;
	int count = 0;
	cin >> m >> n >> t;


	while (t--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++)
			for (int x = x1; x < x2; x++)
				graph[y][x] = 1;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] != 0 || graph[i][j] != 0) continue;
			graph[i][j] = 1;
			Q.push({ i,j });
			count++;
			int bSize = 0;
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				bSize++;
				for (int k = 0; k < 4; k++)
				{
					int nx = cur.first + dx[k];
					int ny = cur.second + dy[k];
					 
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (graph[nx][ny] != 0 || graph[nx][ny] != 0) continue;
					graph[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}// while
			sizes.push_back(bSize);
		}
	}

	sort(sizes.begin(), sizes.end());
	cout << count << '\n';
	for (auto num : sizes) {
		cout << num << ' ';
	}
}