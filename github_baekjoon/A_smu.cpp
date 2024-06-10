#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n, t, c;
bool alp[26];
string s,s2;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> s;
	for (int i = 0; i < s.length(); i++) {
		t = s[i] - 'a';
		if (!alp[t]) {
			alp[t] = 1;
			s2.push_back(s[i]);
		}
		else c++;
	}
	s2=to_string(n+1906)+s2+to_string(c + 4);
	reverse(s2.begin(), s2.end());
	cout << "smupc_" << s2;
	return 0;
}