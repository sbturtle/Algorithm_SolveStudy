/*
	1. bfs�� ���� �� �������� ��ġ ã��  -> cBoard ���� ���� 1�� ���� 2������.... ����
	2. board�� �������� bfs �������� �ٴٸ� �߰� ������ -> ī��Ʈ ���� -> cBoard�� �ٸ� ���� �߽߰� result ���� ���� ����
*/
#include <bits/stdc++.h>
using namespace std;


int graph[304][304];
int cBoard[304][304];
int vis[304][304];
int result;