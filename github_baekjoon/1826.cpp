#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<pair<int, int>>v;
priority_queue<int, vector<int>, less<int>>q;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, a, b,l,p,x=0,cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	cin >> l >> p;
	int i = 0;
	while (p < l) {
		if (i == n) {
			cout << "-1";
			return 0;
		}
		for (; i < n; i++) {
			if (v[i].first <= p) {
				q.push(v[i].second);
			}
			else{
				break;
			}
		}
		if (q.empty()) {
			cout << "-1";
			return 0;
		}
		p += q.top();
		q.pop();
		cnt++;
	}
	cout << cnt;
	return 0;
}