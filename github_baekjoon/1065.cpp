#include<iostream>
#include<string>
using namespace std;
int n,res;
bool han(int k) {
	string s = to_string(k);
	if (s.length() <= 2) return 1;
	char a = s[0];int d = s[1] - s[0];
	for (int i = 2; i < s.length(); i++) {
		if (s[i] != s[0] + i * d) return 0;
	}
	return 1;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (han(i)) res++;
	}
	cout << res;
	return 0;
}