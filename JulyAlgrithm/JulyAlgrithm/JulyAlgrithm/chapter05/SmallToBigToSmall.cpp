#include <iostream>
#define MAX_NUM (1U<<31)

using namespace std;
int array[] = {100,99,98,1,2,3};
int main(){
	int i,n,low,high,mid,max;
	n = 6;
	double a[n],b[n],c[n],inc[n];
	for(int i=0;i<n;i++){
		a[i] = array[i];
	}

	for(i=0;i<n;i++)
		inc[i] = (unsigned)MAX_NUM;

	int j;


	for(i=0;i<n;i++){
		low = 0;high = i;
		while(low<high){
			mid = low +(high-low)*0.5;
			if(inc[mid]<a[i])low=mid+1;
			else high = mid;
		}
		b[i] = low+1;
		inc[low] = a[i];

		cout<<"i:"<<i<<"low:"<<low<<"high:"<<high<<endl;
		for(j=0;j<n;j++)cout<<b[i]<<" ";
			cout<<endl;
		for(j=0;j<n;j++)cout<<inc[i]<<" ";
			cout<<endl;

	}


	return 0;
}