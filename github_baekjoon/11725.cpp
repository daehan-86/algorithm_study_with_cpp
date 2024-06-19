#include<iostream>
#include<vector>
using namespace std;
int n,a,b, visit[100001];
vector<int>v[100001];
void dp(int x) {
	for (int o : v[x]) {
		if (!visit[o]) {
			visit[o] = x;
			dp(o);
		}
	}
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dp(1);
	for (int i = 2; i <= n; i++) {
		cout << visit[i] << "\n";
	}
	return 0;
}