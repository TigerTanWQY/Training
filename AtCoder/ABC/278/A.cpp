#include <iostream>
#include <deque>
using namespace std;

deque<int> d;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 1, x; i <= n; ++i)
	{
		cin >> x;
		d.push_back(x);
	}
	while(k--)
	{
		d.push_back(0);
		d.pop_front();
	}
	for(const auto &p: d)
		cout << p << ' ';
	return 0;
}