#include "stdafx.h"
#include "LeftRouteString.h"



void leftRouteStringMain(){
	violenceMoveSample();
	pointerMethodOneSample();
	pointerMethodTwoSample();
}

void pointerMethodTwoSample(){
	string  s = "abcedfg";
	int moveNum = 3;
	pointerMethodTwo(s,moveNum);
	cout<<s<<endl;
}

void pointerMethodTwo(string &str,int m){
	if(str.length()==0 || m<=0)
		return;

	int n = str.length();

	if(m % n <= 0)
		return;

	int p1 = 0,p2 = m;

	while(true){
		swap(str[p1],str[p2]);
		p1++;
		if(p2<n-1){
			p2++;
		}else{
			break;
		}
	}

	int r = m-n%m;
	while(r--){
		int i = p1;
		char temp = str[p1];
		while(i<p2){
			str[i] = str[i+1];
			i++;
		}
		str[p2] = temp;
	}
	

}

void pointerMethodOneSample(){
	string  s = "abcedfg";
	int moveNum = 3;
	pointerMethodOne(s,moveNum);
	cout<<s<<endl;
}
void pointerMethodOne(string &str,int m){
	if(str.length()==0 || m<=0)
		return;

	int n = str.length();

	if(m % n <= 0)
		return;

	int p1 = 0,p2 = m;
	int k = (n - m) - n%m;

	while(k--){
		swap(str[p1],str[p2]);
		p1++;
		p2++;
	}

	int r = n-p2;
	while(r--){
		int i = p2;
		while(i>p1){
			swap(str[i],str[i-1]);
			i--;
		}
		p2++;
		p1++;

	}
}

void violenceMoveSample(){
	char s[] = "abcdef";
	violenceMove(s,7,3);
	cout<<s<<endl;
}

//left move m times
void violenceMove(char *s,int n,int m){
	for(;m>0;m--){
		leftShiftOne(s,n);
	}
}

//move one char from the beginning to the end
// attention: the end is '\0'
void leftShiftOne(char *s,int n){
	char temp = s[0];
	for(int i=1;i<n-1;i++ ){
		s[i-1] = s[i];
	}
	s[n-2] = temp;
}
