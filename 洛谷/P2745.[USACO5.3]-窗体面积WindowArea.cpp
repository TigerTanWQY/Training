#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
using namespace std;
using LL = long long;

constexpr const int INF = 2147483647;
int qread(){
	int w=1,c,ret;
	while((c=getchar())> '9'||c< '0')
		w=(c=='-'?-1:1);
	ret=c-'0';
	while((c=getchar())>='0' && c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
int hsh(char ID){
	if('a'<=ID && ID<='z') return ID-'a'+1;
	if('A'<=ID && ID<='Z') return ID-'A'+1+26;
	return ID-'0'+26+26+1;
}
char readc()
{ char c; while(((c=getchar())=='('||c==')'||c==' '||c=='\n'||c=='\r') && c!=EOF); return c; }
const int MAXN =26+26+10+3;
int X1[MAXN],Y1[MAXN],X2[MAXN],Y2[MAXN],rd;
int bef[MAXN],nxt[MAXN];
void dlt(int ID){
	nxt[bef[ID]]=nxt[ID],bef[nxt[ID]]=bef[ID];
}
void ist(int bf,int ID){
	bef[ID]=bf,nxt[ID]=nxt[bf],bef[nxt[bf]]=ID,nxt[bf]=ID;
}
int e=MAXN-1,tot,tp1,tp2,Q1[MAXN*2],Q2[MAXN*2];
bool use[MAXN*2][MAXN*2];
map<int,int> mmpA,mmpB;
/*

*/
int main(){
	bef[e]=0,nxt[0]=e;
	while((rd=readc())!=EOF){
		int ID=hsh(readc());
		if(rd=='w'){
			ist(0,ID),X1[ID]=qread(),Y1[ID]=qread(),
			X2[ID]=qread(),Y2[ID]=qread();
			if(X1[ID]>X2[ID]) swap(X1[ID],X2[ID]);
			if(Y1[ID]>Y2[ID]) swap(Y1[ID],Y2[ID]);
		} else if(rd=='d') dlt(ID);
		else if(rd=='t') dlt(ID),ist(0,ID);
		else if(rd=='b') dlt(ID),ist(bef[e],ID);
		else if(rd=='s'){
			mmpA.clear(),mmpB.clear(); tp1=tp2=0; int ans=0;
			for(int i=0;i!=ID;){
				i=nxt[i];
				Q1[++tp1]=X1[i],Q1[++tp1]=X2[i],Q2[++tp2]=Y1[i],Q2[++tp2]=Y2[i];
			}
			sort(Q1+1,Q1+1+tp1),sort(Q2+1,Q2+1+tp2);
			tp1=unique(Q1+1,Q1+1+tp1)-Q1-1,tp2=unique(Q2+1,Q2+1+tp2)-Q2-1;
			up(1,tp1,i) mmpA[Q1[i]]=i;up(1,tp2,i) mmpB[Q2[i]]=i;
			memset(use,0,sizeof(use));
			for(int i=nxt[0];i!=ID;i=nxt[i])
				up(mmpA[X1[i]],mmpA[X2[i]]-1,a)
				up(mmpB[Y1[i]],mmpB[Y2[i]]-1,b) use[a][b]=true;
			up(mmpA[X1[ID]],mmpA[X2[ID]]-1,a)
			up(mmpB[Y1[ID]],mmpB[Y2[ID]]-1,b)
			if(!use[a][b]) ans+=(Q1[a+1]-Q1[a])*(Q2[b+1]-Q2[b]);
			printf("%.3lf\n",100.0*ans/((X2[ID]-X1[ID])*(Y2[ID]-Y1[ID])));
		}
	}
	return 0;
}
