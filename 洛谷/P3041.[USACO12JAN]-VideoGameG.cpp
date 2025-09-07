#include<bits/stdc++.h>
#define re int
using namespace std;

 int read()
{
  int x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
 void print(int x)
{
  if(x<0)putchar('-'),x=-x;
  if(x/10)print(x/10);
  putchar(x%10+'0');
}
int n,k,ch[400][3],v[400],f[1002][400],fail[400],cnt,ans;
char s[20];
 void insert()
{
	scanf("%s",s+1);int len=strlen(s+1),u=0;
	for(re i=1;i<=len;i++)
	{
		int x=s[i]-'A';
		if(!ch[u][x])ch[u][x]=++cnt;
		u=ch[u][x];
	}
	v[u]++;
}
 void get_fail()
{
	queue<int>q;
	for(re i=0;i<3;i++)if(ch[0][i])q.push(ch[0][i]);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(re i=0;i<3;i++)
		{
			if(ch[u][i])fail[ch[u][i]]=ch[fail[u]][i],q.push(ch[u][i]);
			else ch[u][i]=ch[fail[u]][i];
		}
		v[u]+=v[fail[u]];
	}
}
 void dp()
{
	memset(f,128,sizeof(f)); //here
	for(re i=0;i<=k;i++)f[i][0]=0;
	for(re i=1;i<=k;i++)
	for(re j=0;j<=cnt;j++)
	for(re l=0;l<3;l++)
	f[i][ch[j][l]]=max(f[i][ch[j][l]],f[i-1][j]+v[ch[j][l]]);
}
signed main()
{
	n=read();k=read();
	for(re i=1;i<=n;i++)insert();
	get_fail();dp();
	for(re i=1;i<=cnt;i++)ans=max(ans,f[k][i]);
	printf("%d",ans);
	return 0;
}
