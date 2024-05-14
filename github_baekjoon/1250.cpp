#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
typedef tuple<int, int, bool>t;
struct compare {
	bool operator() (t& A, t& B) {
		int &a = get<0>(A), &b = get<1>(A), &c = get<0>(B), &d = get<1>(B);
		if (a == c) return b > d;
		else return a < c;
	}
};
priority_queue <t, vector<t>, compare>pq;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, k, start=0;
	char p,s;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (start == i) p = s;
		else {
			if (p != s) {
				bool state = (start <= k - 1 && k - 1 < i);
				pq.push({ i - start,start,state });
		//		cout << "³ÖÀ»°Ô : " << i - start<< "\n";
				start = i;
				p = s;
			}
		}
	}
	if (start != n) {
		bool state = (start <= k - 1 && k - 1 < n);
		pq.push({ n - start,start,state });
	}
	int cnt = 0;
	while (!pq.empty()) {
	//	cout << get<0>(pq.top()) << " " << get<1>(pq.top()) << "\n";
		cnt++;
		if (get<2>(pq.top())) {
			cout << cnt<<"\n";
			break;
		}
		pq.pop();
	}
	return 0;
}