#include<iostream>
using namespace std;
int n, m, map[501][501], arr1[501], arr2[501];
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = n-1; i >=0; i--) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> arr1[i];
		for (int j = 0; j < n; j++) {
			if (map[j][i]) map[j][i] = arr1[i];
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
		for (int j = 0; j < m; j++) {
			if (map[i][j]>arr2[i]) map[i][j] = arr2[i];
		}
	}


	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < m; j++) {
			t = max(t, map[i][j]);
		}
		if (t != arr2[i]) {
			cout << "-1";
			return 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int t = 0;
		for (int j = 0; j < n; j++) {
			t = max(t, map[j][i]);
		}
		if (t != arr1[i]) {
			cout << "-1";
			return 0;
		}
	}


	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}