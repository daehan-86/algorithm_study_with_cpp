#include<iostream>
#include<vector>
#include<algorithm>
#define q 1000000007
using namespace std;
int n, m, k, a, b;
vector<int>v[100001];
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		v.push_back({ a,i });
	}
	sort(v.begin(), v.end());


	return 0;
}