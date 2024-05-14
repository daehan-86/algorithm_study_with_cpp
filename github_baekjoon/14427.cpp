#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
typedef tuple<int, int, int> t;
priority_queue<t, vector<t>, greater<t>>q;
int n, a, b, c, m, v_t[100001];
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		q.push({ a,i,0 });
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a;
		if (a - 1) {
			while (1) {
				a = get<0>(q.top()), b = get<1>(q.top()), c = get<2>(q.top());
				if (c < v_t[b]) {
					q.pop();
					continue;
				}
				cout << b << "\n";
				break;
			}
		}
		else {
			cin >> a >> b;
			q.push({ b,a,i });
			v_t[a] = i;
		}
	}
	return 0;
}