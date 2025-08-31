#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
typedef pair<double,double> PDD;

const int N=20;
int n;
double a[N][N];
double cur[N],np[N];
double d[N];
double ans[N],minans=1e18;
PDD q[N];

double rand(double l,double r){
    l=max(l,-2e4);
    r=max(r,-2e4);
    l=min(l,2e4);
    r=min(r,2e4);
    return (double)rand()/RAND_MAX*(r-l)+l;
}

double dist(double a[],double b[]){
    double sum=0;
    for(int i=1;i<=n;i++){
        double d=a[i]-b[i];
        sum+=d*d;
    }
    return sum;
}

double calc(double p[]){
    double avg=0,res=0;
    for(int i=1;i<=n+1;i++){
        d[i]=dist(p,a[i]);
        avg+=d[i];
    }
    avg/=n+1;
    for(int i=1;i<=n+1;i++){
        double dif=avg-d[i];
        res+=dif*dif;
    }
    if(res<minans){
        for(int i=1;i<=n;i++)
            ans[i]=p[i];
        minans=res;
    }
    return res;
}

void SA(){
    for(int i=1;i<=n;i++)
        cur[i]=rand(-20000,20000);
    for(double t=200000;t>1e-6;t*=0.99){
        for(int i=1;i<=n;i++)
            np[i]=rand(cur[i]-t,cur[i]+t);
        double dt=calc(np)-calc(cur);
        if(exp(-dt/t)>rand(0,1))
            for(int i=1;i<=n;i++)
                cur[i]=np[i];
    }
}

int main(){
	srand(time(nullptr));
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=n;j++)
            scanf("%lf",&a[i][j]);
    while((double)clock()/CLOCKS_PER_SEC<0.9)
        SA();
    for(int i=1;i<=n;i++)
        printf("%.3lf ",ans[i]);
    return 0;
}