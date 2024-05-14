#include<iostream>
#include<queue>
using namespace std;
typedef pair<double, int> pp;
priority_queue<pp>q;
double mi = 1000000;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	double t,a;
	int n,c=0;
	cin >> t >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		q.push({ a,1 });
		mi = min(mi, a);
	}
	while (!q.empty()) {
		double k = q.top().first, m = q.top().second;
		q.pop();
		if (mi / k > t) {
			cout << c;
			return 0;
		}
		q.push({ k * m / (m + 1),m + 1 });
		mi = min(mi, k * m / (m + 1));
		c++;
	}
	return 0;
}