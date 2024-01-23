//����
//�� �ٷ� �� ������ �����͸� �����Ϸ��� �Ѵ�.�� ������� ���� �ҹ��ڸ��� ����� �� �ִ� �������, �ִ� 600, 000���ڱ��� �Է��� �� �ִ�.
//
//�� �����⿡�� 'Ŀ��'��� ���� �ִµ�, Ŀ���� ������ �� ��(ù ��° ������ ����), ������ �� ��(������ ������ ������), �Ǵ� ���� �߰� ������ ��(��� ���ӵ� �� ���� ����)�� ��ġ�� �� �ִ�.
// �� ���̰� L�� ���ڿ��� ���� �����⿡ �ԷµǾ� ������, Ŀ���� ��ġ�� �� �ִ� ���� L + 1���� ��찡 �ִ�.
//
//�� �����Ⱑ �����ϴ� ��ɾ�� ������ ����.
//
//L		Ŀ���� �������� �� ĭ �ű�(Ŀ���� ������ �� ���̸� ���õ�)
//D	Ŀ���� ���������� �� ĭ �ű�(Ŀ���� ������ �� ���̸� ���õ�)
//B	Ŀ�� ���ʿ� �ִ� ���ڸ� ������(Ŀ���� ������ �� ���̸� ���õ�)
//		������ ���� Ŀ���� �� ĭ �������� �̵��� ��ó�� ��Ÿ������, ������ Ŀ���� �����ʿ� �ִ� ���ڴ� �״����
//P $	$��� ���ڸ� Ŀ�� ���ʿ� �߰���
//�ʱ⿡ �����⿡ �ԷµǾ� �ִ� ���ڿ��� �־�����, �� ���� �Է��� ��ɾ ���ʷ� �־����� ��, ��� ��ɾ �����ϰ� �� �� �����⿡ �ԷµǾ� �ִ� ���ڿ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// ��, ��ɾ ����Ǳ� ���� Ŀ���� ������ �� �ڿ� ��ġ�ϰ� �ִٰ� �Ѵ�.
//
//�Է�
//ù° �ٿ��� �ʱ⿡ �����⿡ �ԷµǾ� �ִ� ���ڿ��� �־�����.�� ���ڿ��� ���̰� N�̰�, ���� �ҹ��ڷθ� �̷���� ������, 
//���̴� 100, 000�� ���� �ʴ´�.��° �ٿ��� �Է��� ��ɾ��� ������ ��Ÿ���� ���� M(1 �� M �� 500, 000)�� �־�����.
//��° �ٺ��� M���� �ٿ� ���� �Է��� ��ɾ ������� �־�����.��ɾ�� ���� �� ���� �� �ϳ��� ���·θ� �־�����.

#include <bits/stdc++.h>
using namespace std;
const int MX = 1000005;
int pre[MX], nxt[MX];
char  dat[MX];
int unused = 1;
int length = 0;

void insert(int addr, char ch) {
	dat[unused] = ch;

	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[unused] = nxt[addr];

	pre[unused] = addr;
	nxt[addr] = unused;

	unused++;
	length++;
}
void erase(int addr) {
	if (nxt[addr] != -1)  pre[nxt[addr]] = pre[addr];
	nxt[pre[addr]] = nxt[addr];
	length--;
}

void printAll() {
	int cur = nxt[0];
	while (cur != -1) {
		cout << dat[cur];
		cur = nxt[cur];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);

	int focus;

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		insert(i, str[i]);
	}
	focus = str.length();

	int m;
	cin >> m;

	while (m--) {
		char op;
		cin >> op;

		if (op == 'L') {				//(Ŀ���� ������ �� ���̸� ���õ�)
			if (focus != 0)	focus = pre[focus];
		}
		else if (op == 'D') {		// Ŀ���� ������ �� ���̸� ���õ�
			if (nxt[focus] != -1)	focus = nxt[focus];

		}
		else if (op == 'B') {		// Ŀ���� ������ �� ���̸� ���õ�
			if (focus != 0) {
				int temp = pre[focus];
				erase(focus);
				focus = temp;
			}
		}
		else {	// P �Է½�
			char ch;
			cin >> ch;
			int temp = unused;
			insert(focus, ch);
			focus = temp;

		}
	}
	printAll();
}