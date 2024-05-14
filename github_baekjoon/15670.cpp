#include<iostream>
#include<vector>
#include<algorithm>
#define INF 2147483647
using namespace std;
int n, m, a, b, t = 2147483647, cnt;
vector<int>v, arr;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	v.push_back(0);
	arr.push_back(INF);
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
		if (t > a)cnt++;
		v.push_back(cnt);
		t = a;
	}
	v.push_back(cnt + 1);
	arr.push_back(0);
	while (m--) {
		cin >> a >> b;
		int t = (b - a + 1) - (v[b] - v[a]);
		t += v[a - 1] + v[n] - v[b + 1] + 1;
		if (arr[b] > arr[a - 1])t--;
		if (arr[a] < arr[b + 1])t--;
		cout << t << "\n";
	}
	return 0;
}