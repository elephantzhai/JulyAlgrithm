#include <iostream>
using namespace std;

void cycle_leader(int *a,int from,int mod){
	int last = a[from],t,i;
	for(int i=from*2%mod;i!=from;i = i*2%mod){
		t= a[i];
		a[i] = last;
		last = t;
	}
	a[from] = last;
}

void reverse(int *a,int from,int to){
	int t;
	for(;from<to;++from,--to){
		t = a[from];
		a[from] = a[to];
		a[to] = t;
	}
}

void right_rotate(int *a,int num,int n){
	reverse(a,1,n-num);
	reverse(a,n-num+1,n);
	reverse(a,1,n);
}

void perfect_shuffle3(int *a,int n){
	int n2,m,i,k,t;

	for(;n>1;){
		n2 = n*2;
		for(k=0,m=1;n2/m>=3;++k,m*=3);
		
		m/=2;
		right_rotate(a+m,m,n);
		for(i = 0,t=1;i<k;++i,t*=3){
			cycle_leader(a,t,m*2+1);
		}

		a += m*2;
		n-=m;
	}
	t = a[1];
	a[1] = a[2];
	a[2]  =t;
}


int main(){
	int a[] = {0,1,2,3,4,5,6,7,8};
	int n = 4,n2 = n*2,t;
	perfect_shuffle3(a,n);
	for(int i=2;i<=n2;i+=2){
		t = a[i-1];
		a[i-1] = a[i];
		a[i] = t;
	}
	for(int i=1;i<=n2;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;

}