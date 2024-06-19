#include<iostream>
#include<string>
#include<vector>
#include<set>
#define INF 2147483647
using namespace std;
typedef pair<int, int> ii;
string tar, s;
vector<int>map[101];
vector<int>result(50001);
int n, spell[26] = { 2,2,2,3,3,3,4,4,1,1,5,5,6,6,0,7,0,7,7,8,8,8,9,9,9,0 };
ii cache[101];
vector<string> vs;
ii dp(int d) {
	if (d == tar.length()) {
		return { 0,0 };
	}
	ii& ret = cache[d];
	if (ret.first != -1) return ret;
	ret = { INF,0 };
	for (int i = 0; i < map[d].size(); i++) {
		ii t = dp(d + vs[map[d][i]].length());
		t.second = map[d][i];
		if (t.first!=INF&&ret.first > t.first+1) {
			ret = { t.first + 1,t.second };
		}
	}
	return ret;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> tar;
	cin >> n;
	int word = 0;
	for (int i = 0; i < 101; i++) cache[i] = { -1,0 };
	for (int i = 0; i < n; i++) {
		cin >> s;
		string t;
		bool state = 1;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] < 'a' || s[j]>'z') {
				state = 0;
				break;
			}
			t.push_back('0' + spell[s[j] - 'a']);
		}
		if (state) {
			vs.push_back(s);
			vector<int>table(t.length() + 1, 0);
			table[0] = -1;
			int j = 0;
			for (int k = 1; k < t.length(); k++) {
				while (t[j] != t[k] && j > 0) {
					j = table[j];
				}
				if (t[j] == t[k]) {
					table[k + 1] = ++j;
				}
			}

			int distance = 0, idx = 0, cnt = 0;
			while (1) {
				idx = 0;
				if ((idx + distance) + t.length() > tar.length()) break;
				while (tar[idx + distance] == t[cnt]) {
					cnt++;
					idx++;
					if (cnt == t.length()) {
						map[distance].push_back(word);
						break;
					}
				}
				distance = distance + (cnt - table[cnt]);
				cnt = 0;
			}
			word++;
		}
	}
	vector<int>res;
	ii k = dp(0);
	if (k.first == INF) {
		cout << "0\nNo solution.\n";
	}
	else {
		cout << k.first << "\n";
		int a = 0;
		for (int i = 0; i < k.first; i++) {
			cout << vs[cache[a].second] << "\n";
			a += vs[cache[a].second].length();
		}
	}
	return 0;
}