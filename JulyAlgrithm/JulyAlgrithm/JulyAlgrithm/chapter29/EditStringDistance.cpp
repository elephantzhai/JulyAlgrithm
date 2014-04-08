#include <iostream>
using namespace std;



int maxProdect(char *ss,char *sd,int lens,int lend){
	int dp[100][100];
	char s[100],d[100];
	int i,j;
	for(i=0;i<lens;i++){
		s[i] = *ss++;
	}
	for(i=0;i<lend;i++){
		d[i] = *sd++;
	}
	for(i=0;i<=max(lend,lens);i++){
		dp[i][0] = i;
		dp[0][i] = i;
	}

	for(i=1;i<=lens;i++){
		for(j=1;j<=lend;j++){
			if(s[i-1]==d[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]+1));
		}
	}
	return dp[lens][lend];
}

int main(){
	char s[] = "abcdefg";
	char d[] = "abcddefg";
	int len1 = 7;
	int len2 = 8;
	cout<<maxProdect(s,d,len1,len2)<<endl;
	return 0;
}