#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, a, cnt = 1;
vector<int>v;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int t = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (t * 2 > v[i]) continue;
		cnt++;
		t = v[i];
	}
	cout << cnt;
	return 0;
}