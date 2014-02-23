#include <iostream>
using namespace std;

struct Pair
{
	int begin,end;
};

Pair findSum(int *s,int n,int x){
	int *begin = s;
	int *end = s+n-1;

	while(begin<end){
		if(*begin + *end > x){
			end--;
		}else if(*begin + *end < x){
			begin++;
		}else{
			Pair p;
			p.begin = *begin;
			p.end = *end;
			return p;
		}
	}
}

int search(int array[],int n,int v){
	int left,right,middle;
	left = 0,right = n-1;

	while(left<=right){
		middle = left + (right-left)/2;
		if(array[middle]>v){
			right = middle -1;
		}else if(array[middle]<v){
			left = middle+1;
		}else{
			return middle;
		}
	}
	return -1;
}

int main(){
	int n = 6,sum = 6;
	int arraySorted[]={1,2,3,4,5,6};
	Pair p;
	p = findSum(arraySorted,n,sum);
	cout<<p.begin<<" "<<p.end<<endl;
	cout<<search(arraySorted,n,sum)<<endl;
	return 0;
}