#include "stdafx.h"
#include "LeftRouteString.h"




void leftRouteStringMain(){
	violenceMoveSample();
	pointerMethodOneSample();
	pointerMethodTwoSample();
	recursionSample();
	repeateMoveSample();

}

void repeateMoveSample(){
	string s = "abcdefg";
	int moveNum = 3;
	repeateMove(s,moveNum);
	cout<<s<<endl;
}
void repeateMove(string &str,int m){
	int lenOfStr = str.length();
	int numOfGroup = gcd(lenOfStr,m);
	int elemInSub = lenOfStr/numOfGroup;

	for(int i = 0,j=0 ;i<numOfGroup;i++){
		char temp = str[i];
		for(j = 0;j<elemInSub-1;j++){
			str[(i+j*m)%lenOfStr] = str[(i+(j+1)*m)%lenOfStr];
		}
		str[(i+j*m)%lenOfStr] = temp;
	}
}
int gcd (int m,int n){
	
	if (n==m) return n;
	int r = 1;
	while(r != 0){
		if(n>m) {
			m = m+n;
			n = m-n;
			m = m-n;
		}
		r = m%n;
		m = n;
		n = r;
	}
	return m;

}



void recursionSample(){
	string s = "abcdefg";
	int moveNum = 3;
	recursionString(s,s.length(),moveNum,0,s.length()-1,true);
	cout<<s<<endl;
}
void recursionString(string &str,int n,int m,int head,int tail,bool flag){
	//n:length of string which will be operate m:length of string which should be route
	//head:the begin position of string which wait to be operate tail:the end position of string which wait to be operate
	//flag:true- left turn flase- right turn

	//return condition
	if (head == tail || m == 0)
		return;

	if(flag == true){
		//left turn
		int p1 = head;
		int p2 = head + m;
		int k = (n-m) - n%m;
		for(int i=0;i<k;i++,p1++,p2++){
			swap(str[p1],str[p2]);
		}
		

		recursionString(str,n-k,n%m,p1,tail,false);
	}else{
		//right turn

		int p1 = tail;
		int p2 = tail - m;
		int k = (n - m) - n%m;
		for(int i=0;i<k;i++,p1--,p2--){
			swap(str[p1],str[p2]);
		}

		recursionString(str,n-k,n%m,head,p1,true);
	}

}

void pointerMethodTwoSample(){
	string  s = "abcdefg";
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
	string  s = "abcdefg";
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
