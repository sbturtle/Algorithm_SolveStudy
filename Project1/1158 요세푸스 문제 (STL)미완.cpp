#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());

	reverse(arr.begin(), arr.end());

	for (int num : arr)
		cout << num << '\n';

}