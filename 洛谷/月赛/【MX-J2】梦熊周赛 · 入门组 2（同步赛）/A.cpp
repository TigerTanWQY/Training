#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool flag = false;
    for(int i = 0; !flag && i < 3; ++i) {
        int x1 = 0;
        if(i == 0)
            x1 = a + b;
        else if(i == 1)
            x1 = a - b;
        else
            x1 = a * b;
        for(int j = 0; !flag && j < 3; ++j) {
            int x2 = 0;
            if(j == 0)
                x2 = x1 + c;
            else if(j == 1)
                x2 = x1 - c;
            else
                x2 = x1 * c;
            if(x2 == d)
                flag = true;
        }
    }
    if(flag)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}