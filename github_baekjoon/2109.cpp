#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> p;
int n,a,b,t,s,res;
vector<p>v;
priority_queue<p>q;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ b,a });
	}
	v.push_back({ 0,0 });
	for (int i = 0; i < v.size(); i++) {
		p& o = v[i];
		if (i && t != o.first) {
			for (int j = s; j < i; j++) {
				q.push({ v[j].second,v[j].first});
			}
			s = i;
			while (!q.empty()) {
				res += q.top().first;
				q.pop();
				t--;
				if (t == o.first)break;
			}
		}
		t = o.first;
	}
	cout << res;
	return 0;
}