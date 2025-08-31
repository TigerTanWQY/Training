#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

string goal="123804765"; //目标状态
int gx[]= {-1,0,0,0,1,2,2,2,1}; //目标坐标
int gy[]= {-1,0,1,2,2,2,1,0,0};
int dx[]= {-1,0,1,0}, dy[]= {0,1,0,-1};

int f(string s)  //估价函数: 曼哈顿距离之和
{
    int res=0;
    for(int i=0; i<9; i++)
    {
        int t=s[i]-'0';
        if(t) res+=abs(i/3-gx[t])+abs(i%3-gy[t]);
    }
    return res;
}
int aStar(string start)
{
    unordered_map<string,int> d;
    priority_queue<pair<int,string>> q;
    q.push({-f(start),start});
    d[start]=0;
    while(q.size())
    {
        auto a=q.top();
        q.pop();
        string s=a.second;
        if(s==goal) return d[s]; //边界
        int k=s.find('0');
        int x=k/3, y=k%3; //行列坐标
        for(int i=0; i<4; i++)
        {
            int a=x+dx[i], b=y+dy[i];
            if(a<0||a>=3||b<0||b>=3)continue;
            string t=s;
            swap(t[k],t[a*3+b]); //交换
            if(!d.count(t))
                d[t]=d[s]+1, q.push({-(d[t]+f(t)),t});
        }
    }
}
int main()
{
    char c;
    string str;
    for(int i=0; i<9; i++)cin>>c,str+=c;
    cout<<aStar(str);
}