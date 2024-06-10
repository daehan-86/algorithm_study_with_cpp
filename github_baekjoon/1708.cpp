#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
double dot[100001][2];
vector<pair<int, double>>v;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dot[i][0] >> dot[i][1];
	}

	return 0;
}