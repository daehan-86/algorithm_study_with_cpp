#include<iostream>
#include<vector>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>>q;
priority_queue<int>p;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m, a;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > 0) p.push(a);
		else q.push(a);
	}
	int result = 0;
	if (!q.empty()) result = min(result, q.top());
	if (!p.empty()) result = min(result, -1 * p.top());
	while (!q.empty()) {
		int x = q.top();
		for (int i = 0; i < m; i++) {
			if (q.empty()) break;
			q.pop();
		}
		result += -2 * x;
	}
	while (!p.empty()) {
		int x = p.top();
		for (int i = 0; i < m; i++) {
			if (p.empty()) break;
			p.pop();
		}
		result += 2 * x;
	}
	cout << result;
	return 0;
}