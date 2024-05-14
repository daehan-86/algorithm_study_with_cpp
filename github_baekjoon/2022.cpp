#include<iostream>
#include<cmath>
#define d 0.000001
using namespace std;
double a, b, c;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> a >> b >> c;
	double ma = min(a, b), mi = 0, x = 0;
	double target = 1 / c;
	//cout << c << "\n";
	while (mi < ma) {
		x = (mi + ma) / 2;
		double bp = sqrt(b * b - x * x);
		double ap = sqrt(a * a - x * x);
		double cp = (ap * bp) / (ap + bp);
		//cout << x << " "<<cp << "\n";
		if (c > cp) {
			ma = x-d;
		}
		else if (c < cp) {
			mi = x+d;
		}
		else {
			break;
		}
	}
	cout << x;
	return 0;
}