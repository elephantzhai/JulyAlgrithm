#include <iostream>
#define n 500000
using namespace std;


int main(){
	int sum[n];

	int i,j;

	for(i = 1;i<n;i++){
		sum[i] = 1;
	}

	for(i=2;i<n;i++){
		j = i*2;

		while(j<n){
			sum[j]+=i;
			j+=i;
		}
	}

	for(i=220;i<n;i++){
		if(sum[i]>i && sum[i]<n && sum[sum[i]]==i)
			cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}