#include<bits/stdc++.h>
using namespace std;

int reCount;

int recursion(const char* s, int l, int r) {
	reCount++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s)
{
	cout << recursion(s, 0, strlen(s) - 1) << ' ';
	int n = reCount;
	reCount = 0;
	return n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {

		char str[1001];
		cin >> str;

		cout << isPalindrome(str) << '\n';
	}
}