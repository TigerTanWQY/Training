#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+3, MAXP = 8*MAXN, MAXM = 20*MAXN;
struct _{
	int nxt, to;
}edge[MAXM];
int fst[MAXP], tot;
void Add_Edge(int f, int t){edge[++tot] = _(fst[f], t); fst[f] = tot;}
struct node{
	int son[2], fa;
	#define son(x,opt) t[x].son[opt]
	#define fa(x) t[x].fa
}t[MAXN<<1];
int trie_cnt=1;

vector<int>G[MAXN<<1];
int ist(int len, char *s){
	int x = 1;
	for(int i=1; i<=len; i++){
		if(!son(x,s[i]^48)) son(x,s[i]^48) = ++trie_cnt, fa(son(x,s[i]^48)) = x;
		x = son(x,s[i]^48);
	}
	return x;
}

int Y(int x){return x<<1|1;}
int N(int x){return x<<1;}

char ch[MAXN], *a[MAXN];
int n, node_cnt, unk[MAXN], loc[2][MAXN], len[MAXN];

void build1(){
	for(int i=1; i<=trie_cnt; i++) if(fa(i)) Add_Edge(i+node_cnt,fa(i)+node_cnt);
	for(int i=1, x; i<=n; i++){
		x = loc[0][i]; if(x) Add_Edge(x+node_cnt,Y(i)); if(fa(x)) Add_Edge(N(i),fa(x)+node_cnt);
		x = loc[1][i]; if(x) Add_Edge(x+node_cnt,N(i)); if(fa(x)) Add_Edge(Y(i),fa(x)+node_cnt);
	}
	node_cnt += trie_cnt;
}

void build2(){
	for(int i=1; i<=trie_cnt; i++) if(fa(i)) Add_Edge(fa(i)+node_cnt,i+node_cnt);
	for(int i=1, x; i<=n; i++){
		x = loc[0][i]; if(x) Add_Edge(N(i),x+node_cnt); if(fa(x)) Add_Edge(fa(x)+node_cnt,Y(i));
		x = loc[1][i]; if(x) Add_Edge(Y(i),x+node_cnt); if(fa(x)) Add_Edge(fa(x)+node_cnt,N(i));
	}
	node_cnt += trie_cnt;
}

void build3(){
	int tmp[MAXN], num;
	for(int i=1; i<=trie_cnt; i++){
		num = G[i].size();
		if(num>=2){
			for(int j=1; j<=num; j++)
				tmp[j] = G[i][j-1],
				Add_Edge(tmp[j],j+node_cnt),
				Add_Edge(j+num+node_cnt,tmp[j]^1);
			for(int j=1; j<num; j++)
				Add_Edge(j+node_cnt,j+1+node_cnt),
				Add_Edge(j+node_cnt,tmp[j+1]^1),
				Add_Edge(tmp[j+1],j+num+node_cnt),
				Add_Edge(j+1+num+node_cnt,j+num+node_cnt);
			node_cnt += num*2;
		}
	}
}

int q[MAXP], top, bel[MAXP], dfn[MAXP], low[MAXP], cnt, SCC;
char in[MAXP];
void tarjan(int x){
	q[++top] = x; in[x] = true;
	dfn[x] = low[x] = ++cnt;
	for(int u=fst[x]; u; u=edge[u].nxt){
		int v=edge[u].to;
		if(!dfn[v]) tarjan(v), low[x] = min(low[x],low[v]);
		else if(in[v]) low[x] = min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		SCC++;
		do{
			int tmp = q[top--];
			in[tmp] = false;
			bel[tmp] = SCC;
		}while(q[top+1]!=x);
	}
}

int main(){
	a[1] = ch;
	scanf("%d",&n); node_cnt = Y(n);
	for(int i=1; i<=n; i++){
		scanf("%s",a[i]+1);
		len[i] = strlen(a[i]+1);
		for(int j=1; j<=len[i]; j++) if(a[i][j]=='?') unk[i] = j;
		if(!unk[i]){
			unk[i] = 1;
			if(a[i][1]=='0') Add_Edge(Y(i),N(i)), loc[0][i] = ist(len[i],a[i]), G[loc[0][i]].push_back(N(i));
			else Add_Edge(N(i),Y(i)), loc[1][i] = ist(len[i],a[i]), G[loc[1][i]].push_back(Y(i));
		}else{
			a[i][unk[i]] = '0'; loc[0][i] = ist(len[i],a[i]); G[loc[0][i]].push_back(N(i));
			a[i][unk[i]] = '1'; loc[1][i] = ist(len[i],a[i]); G[loc[1][i]].push_back(Y(i));
		}
		a[i+1] = a[i]+len[i];
	}
	build1(); build2(); build3();
	for(int i=1; i<=node_cnt; i++) if(!dfn[i]) tarjan(i);
	for(int i=1; i<=n; i++) if(bel[N(i)] == bel[Y(i)]) return puts("NO"), 0;
	puts("YES");
	for(int i=1; i<=n; i++) if(bel[N(i)] < bel[Y(i)]) a[i][unk[i]] = '0'; else a[i][unk[i]] = '1';
	for(int i=1; i<=n; i++,putchar('\n')) for( int j=1; j<=len[i]; j++) putchar(a[i][j]);
	return 0;
}
