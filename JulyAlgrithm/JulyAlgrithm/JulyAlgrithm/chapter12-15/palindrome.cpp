#include <iostream>
using namespace std;

bool IsPalindrome(char *s,int n){
	if(s==0 || n<1) return false;
	char *front,*back;
	front = s;
	back = s+n-1;
	while(front < back){
		if(*front != *back) return false;
		front++;
		back--;
	}
	return true;
}

bool IsPalindrome2(char *s, int n){
	if(s==0 || n<1) return false;
	char *first,*back;
	int m = ((n>>1)-1)>=0?(n>>1)-1:0;
	first = s+m;back = s+n-1-m;
	while(first>=s){
		if(*first!=*back) return false;
		first--;back++;
	}
	return true;
}

int LongestPalindrome(char s[],int n){
	int i,j,max;
	if(n<1) return 0;
	max = 0;
	for(i=0;i<n;i++){
		cout<<"i:"<<i<<" ";
		for(j=0;(i-j>=0 )&&(i+j<n); ++j)
			if(s[i-j]!=s[i+j]) break;
		if(j*2-1>max) max = j*2-1;
		cout<<max<<" ";
		for(j=0;(i-j>=0)&&(i+j+1<n);++j)
			if(s[i-j]!=s[i+j+1])break;
		if(j*2>max) max = j*2;
		cout<<max<<" "<<endl;
	}
	return max;
}

int main()
{
	char str[] = "eabcbae";
	int n = 7;
	cout<<IsPalindrome(str,n)<<endl;
	cout<<IsPalindrome2(str,n)<<endl;
	cout<<LongestPalindrome(str,n);
	return 0;
}