#include <iostream>
using namespace std;

bool isEven(int n){
	return n%2==0;
}

void swap(char *a,char *b){
	char tmp;
	tmp = *b;
	*b = *a;
	*a = tmp;
}

void sort(int *pDate,int length,bool (*func)(int)){
	if(pDate == NULL || length ==0){
		return;
	}

	int *pBegin = pDate;
	int *pEnd = pDate+length-1;


	while(pBegin<pEnd){
		if(!func(*pBegin)){
			pBegin++;
			continue;
		}
		if(func(*pEnd)){
			pEnd--;
			continue;
		}
		swap(*pBegin,*pEnd);
	}
}




int main(){
	int a[] = {1,2,3,4,5,6,7};
	int N = 7;
	sort(a,N,isEven);
	for(int i=0;i<N;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
