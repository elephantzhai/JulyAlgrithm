#include <iostream>
using namespace std;

#define MAXLEN 123456
#define K 7
void maxHeap(int array[],int i,int length){
    int largeIndex = -1;
    int left = i*2;
    int right = i*2+1;

    if(left<=length && array[left]>array[i])
        largeIndex = left;
    else
        largeIndex = i;

    if(right<=length && array[right]>array[largeIndex])
        largeIndex = right;

    if(largeIndex != i){
        swap(array[i],array[largeIndex]);
        maxHeap(array,largeIndex,length);
    }

}

void buildHeap(int array[],int length){
    for(int i=length/2;i>=1;i--){
        maxHeap(array,i,length);
    }
}

int main(){
    int array[K+1];
    for(int i = 1;i<=K;i++){
        array[i] = MAXLEN - i;
    }
    buildHeap(array,K);

    for(int i=MAXLEN-(K+1);i>0;i--){
        if(i<array[1]){
            array[1] = i;
            maxHeap(array,1,K);
        }

    }

    cout<<array[1];
    cin>>array[0];



    return 0;
}
