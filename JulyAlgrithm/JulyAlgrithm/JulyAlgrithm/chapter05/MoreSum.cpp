#include <iostream>
#include <list>
#include <memory.h>
#include <stdlib.h>
using namespace std;

list<int> list1;

void find_facetor(int sum,int n){
	if(n<=0 || sum<= 0)
		return;

	if(sum == n){
		list1.reverse();
		for(list<int>::iterator iter = list1.begin();iter != list1.end();iter++)
			cout<<*iter<<"+";
		cout<<n<<endl;
		list1.reverse();
	}
	list1.push_front(n);
	find_facetor(sum-n,n-1);
	list1.pop_front();
	find_facetor(sum,n-1);
}

void sumofsub(int t,int k,int r,int &M ,bool &flag,bool *X)
{
	X[k] = true;
	if(t+k == M){
		flag = true;
		for(int i=1;i<=k;++i){
			if(X[i]==1){
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}
	else{
		if(t+k+(k+1)<=M){
			sumofsub(t+k,k+1,r-k,M,flag,X);
		}

		if((t+r-k>=M)&&(t+(k+1)<=M)){
			X[k] = false;
			sumofsub(t,k+1,r-k,M,flag,X);
		}
	}
}

void search(int &N,int &M)
{
	bool* X = (bool*)malloc(sizeof(bool)*(N+1));
	memset(X,false,sizeof(bool)*(N+1));
	int sum = (N+1)*N*0.5f;
	if(1>M || sum < M)
	{
		cout<<"not found"<<endl;
		return;
	}
	bool f = false;
	sumofsub(0,1,sum,M,f,X);
	if(!f){
		cout<<"not found"<<endl;
	}
	free(X);
}

int main(){
	int sum,n;
	sum = 6;
	n = 3;
	find_facetor(sum,n);
	search(n,sum);
	return 0;
}