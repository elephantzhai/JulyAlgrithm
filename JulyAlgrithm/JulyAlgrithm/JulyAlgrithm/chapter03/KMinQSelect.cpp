#include <iostream>
using namespace std;
#define MAXLEN 123456
#define K 100

void swap(int* a,int* b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;

}

int partition(int  array[],int lo,int hi){
    int key = array[hi];
    int i = lo-1;

    for(int j=lo;j<hi;j++){

        if(array[j]<=key){
            i++;
            swap(array[i],array[j]);
        }
    }

    swap(array[hi],array[i+1]);
/*
    for(int s = 0;s<MAXLEN;s++){
        cout<<array[s]<<" ";
    }
    cout<<endl;
    */

    return i+1;
}

void q_select(int array[],int lo,int hi,int k){
    //cout<<lo<<" "<<hi<<" "<<k<<" "<<endl;
    if(lo==hi){
        cout<<array[hi];
        return;
    }

    int mid = partition(array,lo,hi);
    //cout<<mid<<endl;
    if(mid-lo+1==k){
        cout<<array[mid];
        return;
    }
    if(mid-lo+1>k){
        //cout<<"f"<<endl;
        q_select(array,lo,mid-1,k);
    }else{
        //cout<<"end"<<endl;
        q_select(array,mid+1,hi,k-mid+lo-1);
    }
}

int main(){
    int array[MAXLEN] ;
    for(int i=0;i<MAXLEN;i++){
        array[i] = MAXLEN - i;
    }
    q_select(array,0,MAXLEN-1,K);
    int i;
    cin>>i;
}
