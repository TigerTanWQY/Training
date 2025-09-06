#include<bits/stdc++.h>
using namespace std;
const int N=50005;
int col[N],n,m,sum[1000005],be[N];
int ANS,qnum,cnum,ans[N];
struct qs{
    int l,r,t,id;
}q[N];
struct cs{
    int x,i;
}c[N];
bool cmp(qs x,qs y)
{
    if(be[x.l]!=be[y.l])return x.l<y.l;
    if(be[x.r]!=be[y.r])return x.r<y.r;
    return x.t<y.t;
}
void upd1(int x)
{
    if(!sum[col[x]])
        ++ANS;
    ++sum[col[x]];
}
void upd2(int x)
{
    --sum[col[x]];
    if(!sum[col[x]])
        --ANS;
}
int l,r,now;
void change(int x)
{
    if(c[x].i<=r && c[x].i>=l)
    {
        --sum[col[c[x].i]];
        if(!sum[col[c[x].i]])
            --ANS;
        if(!sum[c[x].x])
            ++ANS;
        ++sum[c[x].x];
    }
    swap(c[x].x,col[c[x].i]);
}
int main()
{
    cin>>n>>m;
    int xx=pow(n,2.0/3.0);
    char opt;
    for(int i=1;i<=n;i++)
    {
        cin>>col[i];
        be[i]=i/xx+1;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>opt;
        if(opt=='Q')
        {
            ++qnum;
            cin>>q[qnum].l>>q[qnum].r;
            q[qnum].t=cnum;
            q[qnum].id=qnum;
        }
        else
        {
            ++cnum;
            cin>>c[cnum].i>>c[cnum].x;
        }
    }
    sort(q+1,q+qnum+1,cmp);
    l=r=ANS=now=0;
    for(int i=1;i<=qnum;i++)
    {
        while(l<q[i].l)upd2(l++);
        while(l>q[i].l)upd1(--l);
        while(r>q[i].r)upd2(r--);
        while(r<q[i].r)upd1(++r);
        while(now<q[i].t)change(++now);
        while(now>q[i].t)change(now--);
        ans[q[i].id]=ANS;
    }
    for(int i=1;i<=qnum;i++)
        cout<<ans[i]<<endl;
    return 0;
}
