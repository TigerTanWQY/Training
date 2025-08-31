#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	multiset<int> st;
	for(int i = 1, x; i < n; ++i) {
		cin >> x;
		st.insert(x);
	}
	if(*st.cbegin() < *min_element(a + 1, a + n + 1)) {
		cout << "-1" << endl;
		return 0;
	}
	vector<int> id;
	for(int i = n; i; --i)
		if(st.lower_bound(a[i]) == st.cend())
			id.push_back(i);
		else
			st.erase(st.lower_bound(a[i]));
	if(!st.empty() || id.size() > 1)
		cout << "-1";
	else
		cout << a[id.front()];
	cout << endl;
	return 0;
}