#include <iostream>
using namespace std;

int binarySearch(int list[],int n,int findNum){
	int left=0,right=n-1;
	int middle =0;
	while(left<=right){
		middle = left +((right - left)>>1);
		if(list[middle]>findNum){
			right = middle-1;
		}else if(list[middle]<findNum){
			left = middle +1;
		}else{
			return middle;
		}
	}
	return -1;
}

int main(){
	int list[] = {1,2,3,4,6,7,8,10,11,13};
	int n = 10;
	int findNum = 8;
	cout<<binarySearch(list,n,findNum);
	return 0;
}