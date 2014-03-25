#include <iostream>
using namespace std;
int moreThanHalfItem(int *list,int n){
	int candidate1,candidate2;
	int times1,times2;
	candidate1=0;
	candidate2=0;
	times1=0;
	times2=0;

	for(int i=0;i<n;i++){
		int num = *list;
		if(times1==0){
			candidate1 = num;
			times1 =1;
		}else if(times2 ==0 && candidate1!=num){
			candidate2 = num;
			times2 = 1;
		}else{
			if(num == candidate1){
				times1++;
			}else if(num == candidate2){
				times2++;
			}else{
				times1--;
				times2--;
			}
		}
		list++;
	}

	int result=-1;
	if(times1>=n/2){
		result = candidate1;
	}else if(times2>=n/2){
		result = candidate2;
	}

	return result;
}

int main(){
	int a[] = {1,2,1,2,2,2,1,2,2};
	int n = 8;
	cout<<moreThanHalfItem(a,n);
	return 0;
}