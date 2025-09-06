#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
typedef pair<int,int> PII;
queue<PII> waiting;
set<PII> running;
__gnu_pbds::priority_queue<PII,greater<>> endtimes;
int n,t,m,p,ans_cnt,last_out_time;
bool assign(int t,int m,int p) {
    set<PII>::iterator it;
    for(it=running.begin(); it!=running.end(); it++) {
        set<PII>::iterator jt=it;
        jt++;
        if(jt!=running.end())
            if(m<=jt->first-(it->first+it->second))
            {
                int start=it->first+it->second;
                running.insert({start,m});
                endtimes.push({t+p,start});
                return true;
            }
    }
    return false;
}
void release(int t) {
    while(!endtimes.empty() && endtimes.top().first<=t) {
        int tmp=endtimes.top().first;
        last_out_time=tmp;
        while(!endtimes.empty() && endtimes.top().first==tmp) {
            PII tmpp=endtimes.top(); endtimes.pop();
            set<PII>::iterator it=running.lower_bound({tmpp.second,0});
            running.erase(it);
        }
        while(!waiting.empty()) {
            PII tmpp=waiting.front();
            if(assign(tmp,tmpp.first,tmpp.second))
                waiting.pop();
            else break;
        }
    }
}
int main() {
    scanf("%d",&n);
    running.insert({-1,1});
    running.insert({n,1});
    while(cin>>t>>m>>p,t || m || p) {
        release(t);
        if(!assign(t,m,p)) {
            waiting.push({m,p});
            ans_cnt++;
        }
    }
    release(1e9+5);
    printf("%d\n%d",last_out_time,ans_cnt);
    return 0;
}
