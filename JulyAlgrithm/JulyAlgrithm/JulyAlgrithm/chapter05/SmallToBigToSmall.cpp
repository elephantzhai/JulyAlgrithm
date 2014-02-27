#include <iostream>
#include <stdio.h>
#define MAX_NUM (1U<<30)

using namespace std;

int main(){
	int i,n,low,high,mid,max;
	n = 6;
	int a[n],b[n],c[n],inc[n];
	int array[] = {1,4,2,5,3,6};
	for(int i=0;i<n;i++){
		a[i] = array[i];
	}

	int j;

	for(int i=0;i<n;i++){
		b[i] = 0;
		inc[i] = (unsigned) MAX_NUM;
	}

	for(int i=0;i<n;i++){
		low = 0;high = i;
		while(low<high){
			mid = low +(high-low)*0.5;
			if(inc[mid]<a[i])low=mid+1;
			else high = mid;
		}
		b[i] = low+1;
		inc[low] = a[i];

	}

	for(int i=0;i<n;i++){
		c[i] = 0;
		inc[i] = (unsigned) MAX_NUM;
	}

	for(int i=n-1;i>=0;i--){
		low = 0;high = i;
		while(low<high){
			mid = low +(high-low)*0.5;
			if(inc[mid]<a[i])low=mid+1;
			else high = mid;
		}
		c[i] = low+1;
		inc[low] = a[i];

	}

	max = 0;
	for(i = 0;i<n;i++)
		if (b[i]+c[i]>max) {max = b[i]+c[i];j=i;}
	cout<<n+1-max<<endl;


	return 0;
}