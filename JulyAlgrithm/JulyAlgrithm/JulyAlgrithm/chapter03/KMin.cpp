#include "stdafx.h"
#include "KMin.h"

#define MAXLEN 123456
#define K 100


void KMinMain(){
	KTimesMinHeapSample();
}

void KTimesMinHeapKMin(int array[],int length ,int k){
	for(int i = length/2-1;i>=0;i--){

	}

}

void KTimesMinHeapKMinSample(){
	int array[MAXLEN];
	for(int i = MAXLEN;i>0;i--){
		array[MAXLEN - i] = i;
	}
	KTimesMinHeapKMin(array,MAXLEN,K);
}