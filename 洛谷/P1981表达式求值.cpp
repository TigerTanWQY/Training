#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	char c;
	cin >> a;
	s.push(a %= 10000);
	while(cin >> c >> b) // 用 scanf 会出问题
		if(c == '*')
		{
			a = s.top();
			s.pop();
			s.push(a * b % 10000);
		}
		else
			s.push(b);
	for(a = 0; !s.empty(); s.pop())
		a = (a + s.top()) % 10000;
	cout << a;
	return 0;
}