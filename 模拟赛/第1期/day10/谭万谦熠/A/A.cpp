#include <iostream>
#include <string>
using namespace std;

const string py[]{"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	for(int i = 0; i < 10; ++i)
	{
		if(py[i] == str)
		{
			cout << i;
			return 0;
		}
		for(int j = 0; j < 10; ++j)
		{
			if(i != 0)
			{
				string num;
				if(i != 1)
					num = py[i] + "shi";
				else
					num = "shi";
				if(j)
					num += py[j];
				if(num == str)
				{
					cout << i * 10 + j;
					return 0;
				}
			}
			for(int k = 0; k < 10; ++k)
			{
				string num = py[i] + "bai";
				if(j > 1)
					num += py[j] + "shi";
				else if(j == 1)
					num += "shi";
				else if(k)
					num += "ling";
				if(k)
					num += py[k];
				if(num == str)
				{
					cout << i * 100 + j * 10 + k;
					return 0;
				}
			}
		}
	}
	return 0;
}