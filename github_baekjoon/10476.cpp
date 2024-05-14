#include<iostream>
using namespace std;

int cache[201][201][2];
int dp(int deep, int k, bool state) {
	int& ret = cache[deep][k][state];
	if (ret) return ret;
	ret = 0;

}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	cout << max(dp(0, k, 0), dp(0, k, 1));
	return 0;
}