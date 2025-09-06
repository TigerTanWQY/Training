
#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
using namespace std;
ifstream fin,fout,fstd;
ofstream fscore,freport;
int score;
const int maxn  = 10001;
void judge()
{
	int n;
    int a[maxn+1];
    int b[maxn+1];
    int L[maxn+1];
    int flag_[maxn+1]={0};
    int h[maxn+1];
	int label_used[maxn+1]={0};
	fin>>n;
	for(int i=1;i<=n-1;i++) fin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)  fout>>L[i];
	
	for(int i=1;i<=n;i++)
	{
		label_used[L[i]]=1;    //�ж϶��� 
	} 
	int sum1=0;
	for(int i=1;i<=n;i++)
		sum1=sum1+label_used[i]; // �ж϶��� 
		
	for(int i=1;i<=n-1;i++)
	{
		h[i]=abs(L[a[i]]-L[b[i]]);  //�жϱ� 
		flag_[h[i]]=1;
	}
	int sum2=0;
	for(int i=1;i<=n-1;i++)
 	    sum2=sum2+flag_[i];  //�жϱ� 
 	
	if((sum1==n) &&(sum2==n-1))
	{
	     fscore<<score<<endl;
	     freport<<"Success"<<endl;
	}
	else
	{
	
	    freport<<"Invalid result!";
	    fscore<<0<<endl;
	}
 	  
}

 int main(int argc,char*argv[])
 {
		
		//put something to fstreams...
	/*
	argv[1]:�����ļ�
	argv[2]:ѡ������ļ� 
	argv[3]:��׼����ļ� 
	argv[4]:�������Ե��ֵ 
	argv[5]:������յ÷ֵ��ļ� 
	argv[6]:������󱨸���ļ� 
	*/
	fin.open(argv[1]);
	fout.open(argv[2]);
	fstd.open(argv[3]);
	fscore.open(argv[5]);
	freport.open(argv[6]);
	
	score=atoi(argv[4]);
	
	judge();
    
	fin.close();
    fout.close();
    fstd.close();
    fscore.close();
    freport.close();
 	return 0;
 }
