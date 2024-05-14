#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> si;
int n, k, m, t, visit[100001], d, x;
vector<si>v;
vector<int>v2;
queue<int>q;
bool root_find(int x) {
	if (x == 1) {
		cout << "1 ";
	}
	else {
		if (!visit[x]) return 1;
		if (root_find(visit[x]))return 1;
		cout << x << " ";
	}
	return 0;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string s;
	cin >> n >> k;
	v2.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> s;
		t = 0;
		for (int j = 0; j < s.length(); j++) {
			t <<= 1;
			t += (s[j] == '1');
		}
		v.push_back({ t,i + 1 });
		v2.push_back(t);
	}
	sort(v.begin(), v.end());
	q.push(1);
	visit[1] = -1;
	while (!q.empty()) {
		t = q.front();
		x = v2[t];
		//cout << t << " " << x << "\n";
		q.pop();
		for (int i = 0; i < k; i++) {
			d = x^(1<<i);
			si tar = { d,0 };
			auto p = lower_bound(v.begin(), v.end(), tar);
			if (p != v.end()) {
				if (p->first != d) continue;
				int nex = p->second;
				if (visit[nex]) continue;
				q.push(nex);
				visit[nex] = t;
			}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> t;
		if (root_find(t)) cout << "-1";
		cout << "\n";
	}
	return 0;
}