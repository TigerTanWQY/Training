#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, minn = 2147483647;
    cin >> T;
    string ansn, ansz, ansb;
    while(T--)
	{
        string name, zj, bl;
        cin >> name >> zj >> bl;
        if(zj != bl)
            if(minn > name.length())
            {
                minn = name.length();
                ansn = name;
                ansz = zj;
                ansb = bl;
            }
    }
    if(minn == 2147483647)
        cout << "AC";
    else
        cout << ansn << " " << ansz << " " << ansb;
    return 0;
}