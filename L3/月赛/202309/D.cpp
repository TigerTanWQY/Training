#include <iostream>
#include <string>
using namespace std;

int a[103][103];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	bool ud = false, lr = false;
	string op;
	cin >> op;
	for(; op != "end"; cin >> op)
		if(op == "ud")
			ud = !ud;
		else if(op == "lr")
			lr = !lr;
	if(ud)
		if(lr)
			for(int i = n; i >= 1; --i)
			{
				for(int j = m; j >= 1; --j)
					cout << a[i][j] << " ";
				cout << "\n";
			}
		else
			for(int i = n; i >= 1; --i)
			{
				for(int j = 1; j <= m; ++j)
					cout << a[i][j] << " ";
				cout << "\n";
			}
	else
		if(lr)
			for(int i = 1; i <= n; ++i)
			{
				for(int j = m; j >= 1; --j)
					cout << a[i][j] << " ";
				cout << "\n";
			}
		else
			for(int i = 1; i <= n; ++i)
			{
				for(int j = 1; j <= m; ++j)
					cout << a[i][j] << " ";
				cout << "\n";
			}
	return 0;
}