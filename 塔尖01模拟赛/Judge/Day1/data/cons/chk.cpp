#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int n,k;
long long C;
int check()
{
	int sum=0;
	for(int i=1;i<=k;i++)
		sum+=a[i];
	if(sum!=n) return 1;
	long long s=0;
	for(long long i=1;i<=k;i++)
		s+=i*a[i];
	if(s!=C) return 1;
	return 0;
}
int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
    int T,t=0;
	T=inf.readInt();//��ȡ����
	while(t<T)
	{
		t++;
		n=inf.readInt();//��ȡ����
		C=inf.readLong();//��ȡ����
		int pans,jans;
    	pans=ouf.readInt();      // ��ȡѡ�����
    	jans=ans.readInt();      // ��ȡ��
    	if (jans!=pans) quitf(_wa, "The %d testdata first line is WA!",t);
    	if(jans==-1&&pans==-1) continue;
   		else
    	{
    		k=ouf.readInt();	// ��ȡѡ�����
    		for(int i=1;i<=k;i++)
    			a[i]=ouf.readInt();	// ��ȡѡ�����
    		if(check()) quitf(_wa, "The %d testdata 2-3 line is WA!",t);
    		k=ans.readInt();// ��ȡ��
    		for(int i=1;i<=k;i++)
    			a[i]=ans.readInt();	// ��ȡ��
    	}
	}
    quitf(_ok, "Correct.");
}
