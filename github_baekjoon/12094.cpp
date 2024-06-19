#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
int n, map[20][20],res;
void copy_m(int(*a)[20], int(*b)[20]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = b[i][j];
}
bool same_m(int a[][20], int b[][20]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != b[i][j])
				return 0;
	return 1;
}
bool possibility(int n_res, int deep) {
	int t = n_res * pow(2, 9 - deep);
	if (res >= t)return 0;
	return 1;
}
int move_m(int m, int map[][20]) {
	stack<int>s;
	int* temp[20], res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			switch (m) {
			case 0: //left
				temp[j] = &map[i][j];
				break;
			case 1: // down
				temp[j] = &map[n - j - 1][i];
				break;
			case 2: // right
				temp[j] = &map[i][n - j - 1];
				break;
			case 3: // up
				temp[j] = &map[j][i];
				break;
			}
		}
		int k = 0;
		for (int j = 0; j < n; j++) {
			if (!*temp[j])continue;
			if (!s.empty()) {
				if (s.top() == *temp[j]) {
					*temp[k] = s.top() * 2;
					res = max(res, *temp[k]);
					s.pop();
					k++;
					continue;
				}
				else {
					*temp[k] = s.top();
					res = max(res, *temp[k]);
					s.pop();
					k++;
				}
			}
			s.push(*temp[j]);
		}
		if (!s.empty()) {
			*temp[k] = s.top();
			res = max(res, *temp[k]);
			s.pop();
			k++;
		}
		for (; k < n; k++) {
			*temp[k] = 0;
		}
	}
	return res;
}
void dp(int d, int map[][20],int max_res) {
	if (d == 10) {
		res = max(res,max_res);
		return;
	}
	int temp[20][20];
	for (int m = 0; m < 4; m++) {
		copy_m(temp, map);
		int n_res = move_m(m,temp);
		if (same_m(map, temp)) continue;
		if (possibility(n_res, d)) dp(d + 1, temp, n_res);
	}
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			res = max(res, map[i][j]);
		}
	}
	dp(0,map,res);
	cout << res;
	return 0;
}