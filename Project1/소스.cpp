#include <bits/stdc++.h>
using namespace std;

int alpha[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 0; i < str1.length(); i++)
		alpha[str1[i] - 'a']++;

	for (int i = 0; i < str2.length(); i++)
		alpha[str2[i] - 'a']--;

	int cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] == 0)
			continue;
		cnt += abs(alpha[i]);
	}

	cout << cnt;
	return 0;
}