#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,a,b, d;
vector<pair<int, int>>v;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	v.push_back({ 1,1 });
	for (int i = 2; i <= n; i++) {
		cin >> a >> b;
		d = (v[a].first + b - 1) % (n - i + 1) + 1;

	}

	return 0;
}