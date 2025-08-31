#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf 0x3f3f3f3f
const int maxn = 50000+5;
int Max[maxn<<2],a[maxn],last[maxn],ans[maxn];
struct node{
    int l,r,id;
    bool friend operator<(const node u,const node v){
        return u.r<v.r;
    }
}p[maxn];
void build(int l,int r,int rt){
    Max[rt]=0;
    if(l==r) return ;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
void push_up(int rt){
    Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
void update(int l,int r,int rt,int L,int val){
    if(l==r){
        Max[rt]=max(Max[rt],val);
        return ;
    }
    int m=(l+r)>>1;
    if(L<=m) update(lson,L,val);
    else update(rson,L,val);
    push_up(rt);
}
int query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R) {
        return Max[rt];
    }
    int m=(l+r)>>1;
    int ans=0;
    if(L<=m) ans=max(ans,query(lson,L,R));
    if(R>m)  ans=max(ans,query(rson,L,R));
    return ans;
}
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(last,0,sizeof(last));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d",&p[i].l,&p[i].r);
            p[i].id=i;
        }
        sort(p+1,p+1+m);
        int j=1;
        build(1,n,1);
        for(int i=1;i<=n;i++){
            for(int k=1;k*k<=a[i];k++){
                if(a[i]%k==0){
                    if(last[k])
                        update(1,n,1,last[k],k);
                    if(last[a[i]/k]&&k!=a[i]/k)
                        update(1,n,1,last[a[i]/k],a[i]/k);
                    last[k]=i;
                    last[a[i]/k]=i;
                }
            }
            while(p[j].r<=i){
                if(j>m) break;
                if(p[j].l>p[j].r) ans[p[j].id]=0;
                else ans[p[j].id]=query(1,n,1,p[j].l,p[j].r);
                j++;
            }
        }
        for(int i=1;i<=m;i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
