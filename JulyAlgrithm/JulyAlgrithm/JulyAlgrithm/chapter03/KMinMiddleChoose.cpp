#include<iostream>
using namespace std;

#define MAXLEN 123456
#define K 100

int q_select(int array[],int k,int left,int right){
    if(k>right || k < left){
        cout<<"wrong "<<k<<" "<<left<<" "<<right;
        return false;
    }

    int midIndex = (left + right) / 2;
    if(array[left] < array[midIndex])
        swap(array[left],array[midIndex]);
    if(array[right] < array[midIndex])
        swap(array[left],array[midIndex]);
    if(array[right] < array[left])
        swap(array[right],array[left]);
    swap(array[left],array[right]);

    int pivot = array[right];

    int i = left;
    int j = right-1;

    while(42){
        while(array[i]<pivot)
            i++;
        while(array[j]>pivot)
            j--;

        if(i<j)
            swap(array[i],array[j]);
        else
            break;
    }

    swap(array[i],array[right]);

    if (i==k){
        cout<<array[i-1];
        return true;
    }
    else if(i>k)
        return q_select(array,k,left,i-1);
    else
        return q_select(array,k,i+1,right);

}

int main(){
    int array[MAXLEN];
    for(int i = 0;i<MAXLEN;i++){
        array[i] = MAXLEN - i;
    }
    q_select(array,K,0,MAXLEN-1);
    //cout<<array[K-1];
    return 0;

}
