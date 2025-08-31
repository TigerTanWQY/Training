#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int a[5],b[5];
struct node
{ int a,b,c; }
A,B,rootA,rootB;
bool check(node X,node Y)
{ return X.a==Y.a&&X.b==Y.b&&X.c==Y.c; }
int step,k;
node get(node T,int S)
{
	for(step=0;S!=0;step=step+k)
	{
		int x=T.b-T.a,y=T.c-T.b;
		if(x==y)
			return T;
		if(x<y)
		{
			k=min((y-1)/x,S);
			T.a=T.a+k*x;
			T.b=T.b+k*x;
			S=S-k;
		}
		if(x>y)
		{
			k=min((x-1)/y,S);
			T.c=T.c-k*y;
			T.b=T.b-k*y;
			S=S-k;
		}
	}
	return T;
}
int main()
{
	cin>>a[1]>>a[2]>>a[3];
	sort(a+1,a+4);
	A.a=a[1],A.b=a[2],A.c=a[3];
	cin>>b[1]>>b[2]>>b[3];
	sort(b+1,+b+4);
	B.a=b[1],B.b=b[2],B.c=b[3];
	rootA=get(A,INF);
	int cnt1=step;
	rootB=get(B,INF);
	int cnt2=step;
	if(check(rootA,rootB)==false)
	{
		puts("NO");
		return 0;
	}
	if(cnt1<cnt2)
	{
		swap(A,B);
		swap(cnt1,cnt2);
	}
	A=get(A,cnt1-cnt2);
	int l=0,r=cnt2;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(get(A,mid),get(B,mid)))
			r=mid;
		else
			l=mid+1;
	}
	puts("YES");
	cout<<2*l+cnt1-cnt2<<endl;
	return 0;
}
