#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll n_s(ll k) {
	if (!k) return 0;
	ll ret = k * pow(10, k - 1) * 45;
	return ret;
}
ll solve(ll n) {
	if (n < 0) return 0;
	ll p, k=0, t=1, ret=0;
	while (n) {
		p = n % 10;
		ret += p * n_s(k); // ���� ���� ��ǥ�� ���ں��� ���� ���� �����ڸ����� ��
		ret += p * (p - 1) / 2 * pow(10, k); // ���� ���� ��ǥ�� ���ں��� ���� ���� ��
		ret += p * t; // ���� ���� ��ǥ�� ������ ��
		t += p * pow(10, k); // ���� ������ ������ ���� �ڸ��� ����
		k++;
		n /= 10;
	}
	return ret;
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	ll a, b, s=0;
	cin >> a >> b;
	s = solve(b) - solve(a-1);
	cout << s;
	return 0;
}