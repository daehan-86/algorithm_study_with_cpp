#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n;
char a, b, c;
vector<pair<int,int>>v[26];
string s[3];
bool visit[26];
void dp(int x) {
	for (auto o : v[x]) {
		s[0].push_back(x + 'A');
		if (o.first != '.' - 'A') dp(o.first);
		s[1].push_back(x + 'A');
		if (o.second != '.' - 'A') dp(o.second);
		s[2].push_back(x + 'A');
	}
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		v[a - 'A'].push_back({ b - 'A',c - 'A' });
	}
	dp(0);
	for (string res : s)cout << res << "\n";
	return 0;
}