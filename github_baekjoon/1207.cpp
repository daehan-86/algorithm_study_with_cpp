#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
bool part[5][11][11],state;
pair<int,int> wh[5];
int n, M, a, b, map[11][11], ps[5] = { 0,1,2,3,4 },pc[5];
string res;
string s;

void res_input() {
	string t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			t.push_back(map[i][j]+'0');
		}
	}
	if (!state || res.compare(t)>0) {
		for (int i = 0; i < n; i++) {
			res = t;
		}
	}
	state = 1;
}

bool compare(int& l, int& r) {
	if (pc[l] == pc[r]) {
		return l < r;
	}
	return pc[l] > pc[r];
}

int part_s(int p) {
	return ps[p];
}

void input(int p, int x, int y) {
	for (int i = 0; i < a; i++) 
		for (int j = 0; j < b; j++) 
			if(part[part_s(p)][i][j])
				map[i + x][j + y] = part_s(p) +1;
}

void back(int p) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] == part_s(p) +1) map[i][j] = 0;
}

bool check_input(int p, int x, int y) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (part[part_s(p)][i][j] && map[i + x][j + y]) {
				return 0;
			}
		}
	}
	return 1;
}

void dp(int deep) {
	if (deep == 5) {
		res_input();
		return;
	}
	a = wh[part_s(deep)].first, b = wh[part_s(deep)].second;
	for (int i = 0; i <= n - a; i++) {
		for (int j = 0; j <= n - b; j++) {
			if (check_input(deep, i, j)) {
				input(deep,i,j);
				dp(deep + 1);
				a = wh[part_s(deep)].first, b = wh[part_s(deep)].second;
				back(deep);
			}
		}
	}
	return;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	M = n * n;
	for (int i = 0; i < 5; i++) {
		int c = 0;
		cin >> a >> b;
		wh[i] = { a,b };
		for (int j = 0; j < a; j++) {
			cin >> s;
			for (int k = 0; k < b; k++) {
				if (s[k] == '#') {
					part[i][j][k] = 1;
					c++;
				}
			}
		}
		M -= c;
		pc[i] = c;
	}
	if (M != 0) cout << "gg";
	else {
		sort(ps, ps + 5, compare);
		dp(0);
		if (state) {
			for (int i = 0; i < res.size(); i++) {
				cout << res[i];
				if (i % n == n - 1) cout << "\n";
			}
		}
		else {
			cout << "gg";
		}
	}
	return 0;
}