#include <iostream>
using namespace std;
void swap(char &a,char &b){
	char tmp;
	tmp = *b;
	*b = *a;
	*a = tmp;
}

void Permutation(char s[],int first,int num){
	if(num<=1)
		return ;

	for(int i=0;i<first+num;i++){
		swap(s[first],s[i]);
		Permutation(s,first+1,num-1);
	}

}

int main(){
	char s[] = "abcdefg";
	Permutation(s,0,7);
	return 0;
}