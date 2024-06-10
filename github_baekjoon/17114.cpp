#include<iostream>
#include<queue>
using namespace std;
int dim[11], x, n = 1, t, res, temp[11];
int map[1000001];
bool visit[1000001];
queue<pair<int, int>>q;
bool inner(int x) {
	if (x >= 0 && x < n) return 1;
	else return 0;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (int i = 0; i < 11; i++) {
		cin >> dim[i];
		n *= dim[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		if (map[i] == 1) {
			q.push({ i,0 });
			visit[i] = 1;
		}
		else if (map[i] == -1) {
			visit[i] = 1;
		}
	}
	//cout << "asdfasdf\n";
	while (!q.empty()) {
		x = q.front().first, t = q.front().second;
		//cout << x << " " << t << "\n";
		q.pop();
		for (int i = 0; i < 11; i++) {
			temp[i] = x % dim[i];
			x /= dim[i];
		}
		for (int d = 0; d < 11; d++) {
			for (int dd = -1; dd <= 1; dd += 2) {
				temp[d] += dd;
				if (temp[d] >= 0 && temp[d] < dim[d]) {
					int dx = 0;
					for (int i = 10; i >= 0; i--) {
						dx *= dim[i];
						dx += temp[i];
					}
					if (!visit[dx]) {
						visit[dx] = 1;
						q.push({ dx,t + 1 });
					}
				}
				temp[d] -= dd;
			}
		}
		res = max(res, t);
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			cout << "-1";
			return 0;
		}
	}
	cout << res;
	return 0;
}