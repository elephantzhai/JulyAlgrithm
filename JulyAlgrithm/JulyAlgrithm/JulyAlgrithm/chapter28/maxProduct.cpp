#include <iostream>
using namespace std;
double func(double *a,const int n){
	double *maxA = new double[n];
	double *minA = new double[n];
	maxA[0] = minA[0] = a[0];
	double value = maxA[0];
	for(int i=0;i<n;i++){
		maxA[i] = max(max(a[i],maxA[i-1]*a[i]),minA[i-1]*a[i]);
		minA[i] = min(min(a[i],maxA[i-1]*a[i]),minA[i-1]*a[i]);
		value = max(value,maxA[i]);
	}
	return value;

}

int main(){
	double a[] = {-2.5,4,0,3,0.5,8,-1};
	cout<<func(a,7);
	return 0;
}