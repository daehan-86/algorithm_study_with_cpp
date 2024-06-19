#include<iostream>
using namespace std;
int n,c,k,a,b;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> c >> k;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (c >= a && b > k) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}