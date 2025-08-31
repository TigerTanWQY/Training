#include <iostream>
#include <cstring>
#include <stack>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
typedef long long LL;

const LL INF = 0x3f3f3f3f3f3f3f3f;
const int N = 100'003;

struct node0 {
    LL w;
    int u, v, flag;
};

struct node1 {
    LL w;
    int v, next, id;
};

struct node2 {
    bool friend operator<(const node2& n1, const node2& n2)
    { return n1.val>n2.val; }
    LL val;
    int id;
};

stack <int> stk;
node0 pre[N];
node1 edge1[N],edge2[N],edge[2*N];
__gnu_pbds::priority_queue <node2> que;
LL dis1[N],dis2[N];
int first1[N],first2[N],first[N],dfn[N],low[N],book[N],belong[N];
int n,m,num1,num2,num,cnt1,cnt2;

void addedge(node1 *edge,int *first,int u,int v,LL w,int id,int &num)
{
    edge[num].v=v;
    edge[num].w=w;
    edge[num].next=first[u];
    edge[num].id=id;
    first[u]=num++;
}

void dijkstra(node1 *edge,int *first,LL *dis,int s)
{
    node2 cur,tmp;
    LL w;
    int i,u,v;
    while(!que.empty()) que.pop();
    for(i=1;i<=n;i++){
        dis[i]=INF;
        book[i]=0;
    }
    dis[s]=0;
    tmp.id=s,tmp.val=0;
    que.push(tmp);
    while(!que.empty()){
        cur=que.top();
        que.pop();
        u=cur.id;
        if(book[u]) continue;
        book[u]=1;
        for(i=first[u];i!=-1;i=edge[i].next){
            v=edge[i].v,w=edge[i].w;
            if(!book[v]&&dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                tmp.id=v,tmp.val=dis[v];
                que.push(tmp);
            }
        }
    }
}

void dfs(int u,int fa)
{
    int i,v;
    stk.push(u);
    num++;
    dfn[u]=num;
    low[u]=num;
    book[u]=1;
    for(i=first[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(v==fa) continue;
        if(dfn[v]==0)
        {
            dfs(v,u);
            if(low[u]>low[v])
            {
                low[u]=low[v];
            }
            if(low[v]>dfn[u])
            {
                cnt1++;
                pre[edge[i].id].flag=2;
            }
        }
        else if(book[v]==1&&low[u]>dfn[v])
        {
            low[u]=dfn[v];
        }
    }
    if(dfn[u]==low[u])
    {
        cnt2++;
        while(!stk.empty())
        {
            v=stk.top();
            stk.pop();
            book[v]=0;
            belong[v]=cnt2;
            if(u==v) break;
        }
    }
}

void tarjan()
{
    int i,j;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(book,0,sizeof(book));
    memset(belong,0,sizeof(belong));
    num=0,cnt1=0,cnt2=0;
    for(i=1;i<=n;i++){
        if(dfn[i]==0) dfs(i,-1);
    }

}

int main()
{
    LL ans,tmp;
    int i;
    scanf("%d%d",&n,&m);
    memset(first1,-1,sizeof(first1));
    memset(first2,-1,sizeof(first2));
    num1=0,num2=0;
    for(i=1;i<=m;i++){
        scanf("%d%d%lld",&pre[i].u,&pre[i].v,&pre[i].w);
        addedge(edge1,first1,pre[i].u,pre[i].v,pre[i].w,0,num1);
        addedge(edge2,first2,pre[i].v,pre[i].u,pre[i].w,0,num2);
    }
    dijkstra(edge1,first1,dis1,1);
    dijkstra(edge2,first2,dis2,2);
    ans=dis1[2];
    memset(first,-1,sizeof(first));
    num=0;
    for(i=1;i<=m;i++){
        if(dis1[pre[i].u]+pre[i].w+dis2[pre[i].v]==ans){
            pre[i].flag=1;
            addedge(edge,first,pre[i].u,pre[i].v,pre[i].w,i,num);
            addedge(edge,first,pre[i].v,pre[i].u,pre[i].w,i,num);
        }
    }
    tarjan();
    for(i=1;i<=m;i++){
        //printf("***%d***\n",pre[i].flag);
        if(pre[i].flag==0){
            if(dis1[pre[i].v]+pre[i].w+dis2[pre[i].u]<ans){
                printf("HAPPY\n");
            }
            else{
                printf("SOSO\n");
            }
        }
        else if(pre[i].flag==1){
            if(dis1[pre[i].v]+pre[i].w+dis2[pre[i].u]<ans){
                printf("HAPPY\n");
            }
            else{
                printf("SOSO\n");
            }
        }
        else{
             printf("SAD\n");
        }
    }
    return 0;
}