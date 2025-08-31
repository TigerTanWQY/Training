#include <iostream>
#include <vector>
using namespace std;

const int P = 400003;
vector<int> hashmap[P];

int Hash(const int& x)
{ return x % P; }

void Insert(const int& x)
{ hashmap[Hash(x)].push_back(x); }

bool Find(const int& x) {
	for(const auto& p: hashmap[Hash(x)])
		if(p == x)
			return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, tot = 0;
	cin >> n >> m;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		Insert(x);
	}
	for(int i = 1, x; i <= m; ++i) {
		cin >> x;
		if(Find(x))
			++tot;
	}
	if(tot * 2 >= m)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}