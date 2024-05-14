#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int>v[300001];
bool visit[300001];
queue<int>q;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n,a,b;
	cin >> n;
	for (int i = 0; i < n - 2; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visit[1] = 1;
	q.push(1);
	while (!q.empty()) {
		a = q.front();
		q.pop();
		for (int o : v[a]) {
			if (!visit[o]) {
				visit[o] = 1;
				q.push(o);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			cout << "1 " << i;
			break;
		}
	}
	return 0;
}