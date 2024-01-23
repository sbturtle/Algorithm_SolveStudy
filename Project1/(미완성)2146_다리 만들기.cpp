/*
	1. bfs를 통해 각 육지들의 위치 찾기  -> cBoard 같은 곳에 1번 육지 2번육지.... 저장
	2. board를 바탕으로 bfs 육지에서 바다를 발견 했을때 -> 카운트 시작 -> cBoard의 다른 육지 발견시 result 값에 비교후 저장
*/
#include <bits/stdc++.h>
using namespace std;


int graph[304][304];
int cBoard[304][304];
int vis[304][304];
int result;