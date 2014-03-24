#include <iostream>
#include <string.h>
using namespace std;

char FirstCharOccurOnce(char *str,int n){
	int table[256];
	memset(table,0,sizeof(table));
	for(int i = 0;i<n;i++){
		table[(int)(*str)-1]++;
		str++;
	}
	int once=-1;
	for(int i=0;i<255;i++){
		if(table[i]==1){
			once = i;
			break;
		}
	}
	if(once!=-1){
		return (char)(once+1);
	}else{
		return '0';
	}
}

int main(){
	char list[] = "abcdefqghiabcdegfhi";
	int N = 19;
	cout<<FirstCharOccurOnce(list,N);
	return 0;
}