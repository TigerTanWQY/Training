#include <iostream>
#include <set>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	LL S1, S2, S3;
	cin >> n >> S1 >> S2 >> S3;
	set<LL> st;
	st.insert(0);
	LL tot = 0;
	for(int x; n--; ) {
		cin >> x;
		st.insert(tot += x);
	}
	for(const auto& x: st)
		if(st.count(x + S1) && st.count(x + S1 + S2) && st.count(x + S1 + S2 + S3)) {
			cout << "Yes" << endl;
			return 0;
		}
	cout << "No" << endl;
	return 0;
}