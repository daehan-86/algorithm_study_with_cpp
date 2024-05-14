#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int>p;
priority_queue<p, vector<p>, greater<p>>q;
priority_queue<int, vector<int>, greater<int>>qq;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n,a,b,s,e;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		q.push({ a,b });
	}
	while (!q.empty()) {
		s = q.top().first, e = q.top().second;
		q.pop();
		if (qq.empty()) {
			qq.push(e);
		}
		else {
			if (qq.top() <= s) {
				qq.push(e);
				qq.pop();
			}
			else {
				qq.push(e);
			}
		}
	}
	cout << qq.size();
	return 0;
}