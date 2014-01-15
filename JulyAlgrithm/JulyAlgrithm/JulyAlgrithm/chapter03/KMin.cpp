#include "stdafx.h"
#include "KMin.h"

#define MAXLEN 123456
#define K 100


void KMinMain(){
	KTimesMinHeapKMinSample();
}

void heapAdjust(int array[],int i,int length){
	int temp,child;
	for(temp = array[i];i*2+1<length;i = child){
		child = i*2+1;
		if(child<length-1 && array[child+1]<array[child])
			child++;

		if(temp>array[child])
			array[i] = array[child];
		else
			break;

		array[child] = temp;

	}
}

void swap (int* a,int* b){
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

int getMin(int array[],int length,int k){
	int min = array[0];
	swap(&array[0],&array[length-1]);

	int child,temp;
	int i=0,j=k-1;
	for(temp = array[0];j>0 && 2*i+1<length;j--,i=child){
		child = 2*i+1;
		if(child<length-1 && array[child+1]<array[child])
			child++;
		if(temp>array[child])
			array[i] = array[child];
		else
			break;
		array[child] = temp;

	}
	return min;
}

void KTimesMinHeapKMin(int array[],int length ,int k){
	for(int i = length/2-1;i>=0;i--){
		heapAdjust(array,i,length);
	}

	int j = length ;
	for(int i=k;i>0;--j,--i){
		int min = getMin(array,j,i);
		cout<<min<<" ";
	}
	cout<<endl;


}

void KTimesMinHeapKMinSample(){
	int array[MAXLEN];
	for(int i = MAXLEN;i>0;i--){
		array[MAXLEN - i] = i;
	}
	KTimesMinHeapKMin(array,MAXLEN,K);
}