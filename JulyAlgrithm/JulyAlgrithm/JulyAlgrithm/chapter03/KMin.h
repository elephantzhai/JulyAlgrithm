#include <iostream>
#include <string>
using namespace std;

void KMinMain();

void heapAdjust(int array[],int i,int length);
void swap (int* a,int* b);
int getMin(int array[],int length,int k);
void KTimesMinHeapKMin(int array[],int length ,int k);
void KTimesMinHeapKMinSample();