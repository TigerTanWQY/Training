#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	unordered_map<char, int> cnt;
	for(const auto& c: s)
		++cnt[c];
	if(cnt.count('D'))
		cout << "Never give up.";
	else if(!cnt.count('C') && cnt.count('A'))
		cout << "I'm so happy.";
	else
		cout << "This is ok.";
	return 0;
}