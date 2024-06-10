#include<iostream>
#include<string>
using namespace std;
int cnt;
string s;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> s;
	char c='8';
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '?') {

		}
		else if (s[i] != c) {
			cnt++;
			c = s[i];
		}
	}
	cout << cnt;
	return 0;
}