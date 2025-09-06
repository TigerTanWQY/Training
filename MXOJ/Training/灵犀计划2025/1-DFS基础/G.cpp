#include<bits/stdc++.h>
#define sea 1000500
using namespace std;
int n,sz[20];
char symbol[20];
void sear(int k,int s,int q,char c){
    if(k==n){
        if(c=='+'){
            s=s+q;
        }
        else{
            s=s-q;
        }
        if(s==0){
            cout<<"1";
            for(int i=1;i<n;i++){
                cout<<symbol[i]<<sz[i];
            }
            cout<<endl;
        }
    }
    else{
        symbol[k]=' ';
        sear(k+1,s,q*10+sz[k],c);
        symbol[k]='+';
        if(c=='+'){
            sear(k+1,s+q,sz[k],'+');
        }
        else{
            sear(k+1,s-q,sz[k],'+');
        }
        symbol[k]='-';
        if(c=='+'){
            sear(k+1,s+q,sz[k],'-');
        }
        else{
            sear(k+1,s-q,sz[k],'-');
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        sz[i]=i+1;
    }
    sear(1,0,1,'+');
    return 0;
}
