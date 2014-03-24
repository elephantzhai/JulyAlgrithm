#include <iostream>
using namespace std;
void swap(char *a,char *b){
	char tmp;
	tmp = *b;
	*b = *a;
	*a = tmp;
}
void print(char s[]){
	for(int i=0;i<4;i++){
		cout<<s[i];
	}
	cout<<endl;
}

void Permutation(char s[],int first,int num){
	if(num<=1){
		print(s);
		// cout<<"endl";
		return ;
	}
	

	for(int i=first;i<first+num;i++){
		swap(s[first],s[i]);
		Permutation(s,first+1,num-1);
		swap(s[first],s[i]);
	}

}

int main(){
	char s[] = "abcd";
	Permutation(s,0,4);
	return 0;
}