/** ע�⣺������ȷ����пӣ��������˸����ţ�����**/
#include <iostream>
using namespace std;

int f(const int &x)
{ return x * x + 2 * x + 3; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	cout << f(f(f(t) + t) + f(f(t)));
	return 0;
}
