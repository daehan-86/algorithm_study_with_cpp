#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int n, a,res;
vector<int>v;
unordered_map<int, bool>m;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m[v[i] + v[j]] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (m[v[i] - v[j]]) {
				res = max(res, v[i]);
			}
		}
	}
	cout << res;
	return 0;
}