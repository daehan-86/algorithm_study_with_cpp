#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, m, k, a, p,c;
priority_queue<int>q;
vector<int>v;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		q.push(a);
	}
	while (!q.empty()) {
		a = q.top();
		q.pop();
		if (a - m > k) {
			q.push(a - m);
		}
		v.push_back(p / 2 + a);
		p = p / 2 + a;
		c++;
	}
	cout << c << "\n";
	for (auto o : v) {
		cout << o << "\n";
	}
	return 0;
}