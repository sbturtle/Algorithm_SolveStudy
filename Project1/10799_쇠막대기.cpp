#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<char> st;
	int result = 0;

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			st.push(str[i]);

		}
		else if (str[i] == ')') {
			if (str[i - 1] == '(') {
				st.pop();
				result += st.size();
			}
			else {
				result++;
				st.pop();
			}
		}
	}

	cout << result << '\n';
}