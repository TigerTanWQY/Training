#include<bits/stdc++.h>
#define re register
#define fep(i,l,r) for(re int i=l;i<=r;++i)
#define For(i,u) for(re int i=head[u];i;i=e[i].nxt)
#define feb(i,r,l) for(re int i=r;i>=l;--i)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LL long long
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define pr pair<int,int>
#define mpr make_pair
using namespace std;

const int N = 3e3+5;
int n,a,b,sum1[N],sum2[N],ans; bool vis1[N][N],vis2[N][N];
struct Node
{
	int x,y,id;
	inline bool operator <(const Node d1) const {return x+d1.y>y+d1.x;}
}p[N];
priority_queue<int,vector<int>,greater<int> > q;

inline int read() { int s=0,w=1; char ch=getchar(); while(!(ch<='9'&&ch>='0')) {if(ch=='-') w=-1; ch=getchar();} while(ch<='9'&&ch>='0') {s=(s<<1)+(s<<3)+ch-'0'; ch=getchar();} return s*w; }
inline void write(int x) { if(x>=10) write(x/10); putchar(x%10+'0'); }
inline void print(int x,char ch) { if(x<0) putchar('-'),x=~(x-1); write(x); putchar(ch);}

signed main()
{
	n=read(),a=read(),b=read();
	fep(i,1,n) p[i].x=read(),p[i].id=i;
	fep(i,1,n) p[i].y=read();
	sort(p+1,p+1+n);
	fep(i,1,n)
	{
		q.push(p[i].x); sum1[i]=sum1[i-1]+p[i].x;
		fep(j,1,n) vis1[i][j]=vis1[i-1][j]; vis1[i][p[i].id]=1;
		if(q.size()>a)
		{
			sum1[i]-=q.top();
			fep(j,1,n) if(vis1[i][p[j].id]&&q.top()==p[j].x)
			{
				vis1[i][p[j].id]=0; break;
			}
			q.pop();
		}
	}
	while(!q.empty()) q.pop();
	feb(i,n,1)
	{
		q.push(p[i].y); sum2[i]=sum2[i+1]+p[i].y;
		fep(j,1,n) vis2[i][j]=vis2[i+1][j]; vis2[i][p[i].id]=1;
		if(q.size()>b)
		{
			sum2[i]-=q.top();
			fep(j,1,n) if(vis2[i][p[j].id]&&q.top()==p[j].y)
			{
				vis2[i][p[j].id]=0; break;
			}
			q.pop();
		}
	}
	fep(i,a,n-b) ans=max(ans,sum1[i]+sum2[i+1]);
	print(ans,'\n');
	fep(i,a,n-b) if(ans==sum1[i]+sum2[i+1])
	{
		fep(j,1,n) if(vis1[i][j]) print(j,' '); puts("");
		fep(j,1,n) if(vis2[i+1][j]) print(j,' '); puts("");
		break;
	}
	return 0;
}
