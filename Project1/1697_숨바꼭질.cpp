#include <bits/stdc++.h>
using namespace std;

int graph[2000002];
int n, k;
int dx[] = { 1,-1,2 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<int> Q;
	cin >> n >> k;

	graph[n] = 1;

	Q.push(n);
	bool isFind = false;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 3; i++) {
			int nx;
			if (i == 2) nx = cur * dx[i];
			else	nx = cur + dx[i];

			if (nx < 0 || nx >= 2000002) continue;
			if (graph[nx] != 0) continue;
			if (nx == k) isFind = true;

			graph[nx] = graph[cur] + 1;

			Q.push(nx);
		}
		if (isFind) break;
	}

	cout << graph[k] - 1;
}