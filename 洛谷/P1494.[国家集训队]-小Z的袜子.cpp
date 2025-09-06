#include <bits/stdc++.h>
using namespace std;
struct hh
{
	int l,r,id;
	long long len;
}b[60000];
int a[60000],bl[60000],n,m,blo,num[60000];
long long ans1[60000],ans2[60000],tot;
inline bool cmp(const hh &a,const hh &b)
{
	if(bl[a.l]<bl[b.l])return 1;
	if(bl[a.l]>bl[b.l])return 0;
	if(bl[a.l]&1)return a.r<b.r;
	return a.r>b.r;
}
inline char gc()
{
	static char BB[1000000],*S=BB,*T=BB;
	return S==T&&(T=(S=BB)+fread(BB,1,1000000,stdin),S==T)?EOF:*S++;
}
inline int getin()
{
	 int x=0; char ch=gc();
	while(ch<48)ch=gc();
	while(ch>=48)x=x*10+(ch^48),ch=gc();
	return x;
}
inline void add(int x){tot+=((num[x]<<1)|1),num[x]++;}
inline void rem(int x){tot+=1-(num[x]<<1),num[x]--;}
int wt[30];
inline void putout(long long x)
{
	if(!x){putchar(48);return;}
	 int l=0;
	while(x)wt[++l]=x%10,x/=10;
	while(l)putchar(wt[l--]+48);
}
int main()
{
	n=getin(),m=getin();
	 int blo=n/sqrt((m>>1)/3);
	for( int i=1;i<=n;i++)a[i]=getin();
	for( int i=1;i<=m;i++)b[i].l=getin(),b[i].r=getin(),b[i].len=b[i].r-b[i].l+1,b[i].id=i,ans2[i]=1,bl[i]=(i-1)/blo+1;
	sort(b+1,b+m+1,cmp);
	 int l=b[1].l,r=b[1].r;
	for( int i=l;i<=r;i++)add(a[i]);
	 long long fz,fm,g;
	if(tot!=b[1].len)
	{
		fz=tot-b[1].len,fm=b[1].len*(b[1].len-1),g=gcd(fz,fm);
		ans1[b[1].id]=fz/g,ans2[b[1].id]=fm/g;
	}
	for( int i=2;i<=m;i++)
	{
		while(l<b[i].l)rem(a[l++]);
		while(l>b[i].l)add(a[--l]);
		while(r>b[i].r)rem(a[r--]);
		while(r<b[i].r)add(a[++r]);
		if(b[i].len!=tot)
		{
			fz=tot-b[i].len,fm=b[i].len*(b[i].len-1);
			g=__gcd(fz,fm),ans1[b[i].id]=fz/g,ans2[b[i].id]=fm/g;
		}
	}
	for( int i=1;i<=m;i++)putout(ans1[i]),putchar('/'),putout(ans2[i]),putchar(10);
}
