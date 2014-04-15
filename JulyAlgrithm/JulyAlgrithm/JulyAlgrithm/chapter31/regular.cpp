#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

int str_len(char *a){
	if(*a==0){
		return 0;
	}
	char *t = a;
	for(;*t;++t)
		;
	return (int)(t-a);
}
void str_copy(char *a,const char *b,int len){
	for(;len>0;len--,a++,b++){
		*a = *b;
	}
	*a = 0;
}

char *str_join(char *a,const char *b,int lenb){
	char *t;
	if( a == 0){
		t = (char *)malloc(sizeof(char)*(lenb+1));
		str_copy(t,b,lenb);
		return t;
	}else{
		int lena = str_len(a);
		t = (char *)malloc(sizeof(char)*(lena+lenb+2));
		str_copy(t,a,lena);
		*(t+lena) = ' ';
		str_copy(t+lena+1,b,lenb);
		free(a);
		return t;
	}
}

int canMatch(char *input,char *rule){
	if(*rule ==0){
		return 0;
	}
	int r=-1,may;
	if(*rule == '*'){
		r = canMatch(input,rule+1);
		if(*input){
			may = canMatch(input+1,rule);
			if((may>=0) && (++may > r)){
				r = may;
			}
		}
	}
	if(*input == 0){
		return r;
	}
	if((*rule == '?')||(*rule == *input)){
		may = canMatch(input+1,rule+1);
		if((may>=0)&&(++may>r)){
			r = may;
		}
	}
	return r;
}
char* my_find(char input[],char rule[]){
	int len = str_len(input);
	int *match = (int*)malloc(sizeof(int)*len);
	int i,max_pos = -1;
	char *output = 0;

	for(i=0;i<len;++i){
		match[i] = canMatch(input+i,rule);
		if((max_pos<0) || (match[i]>match[max_pos])){
			max_pos = i;
		}
	}

	if((max_pos<0)||(match[max_pos]<=0)){
		output = (char *) malloc(sizeof(char));
		*output = 0;
		return output;
	}

	for(i=0;i<len;){
		if(match[i] == match[max_pos]){
			output = str_join(output,input+i,match[i]);
			i+=match[i];
		}else{
			++i;
		}
	}
	free(match);
	return output;
}

int main(){
	char input[] = "aabcd";
	char rule[] = "a*d";
	cout<<my_find(input,rule)<<endl;
	return 0;
}