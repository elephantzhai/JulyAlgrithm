#include <iostream>
#include <malloc.h>
using namespace std;
char* my_find(char input[],char rule[]){
	int len1,len2;
	for(len1 = 0;input[len1];len1++);
	for(len2 = 0;rule[len2];len2++);
	int MAXN = len1>len2?(len1+1):(len2+1);
	int **dp;

	dp = new int*[len1+1];
	for(int i = 0;i<=len1;i++){
		dp[i] = new int[len2+1];
	}

	dp[0][0] = 0;
	for(int i = 1;i<=len2;i++)
		dp[0][i] = -1;
	for(int i = 1;i<=len1;i++)
		dp[i][0] = 0;

	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if(rule[j-1]=='*'){
				dp[i][j] = -1;
				if(dp[i-1][j-1]!=-1){
					dp[i][j] = dp[i-1][j-1]+1;
				}
				if(dp[i-1][j]!=-1 && dp[i][j]<dp[i-1][j]+1){
					dp[i][j] = dp[i-1][j]+1;
				}
			}else if(rule[j-1]=='?'){
				if(dp[i-1][j-1]!=-1){
					dp[i][j] = dp[i-1][j-1]+1;
				}else{
					dp[i][j] = -1;
				}
			}else{
				if(dp[i-1][j-1]!=-1 && input[i-1]==rule[j-1]){
					dp[i][j] = dp[i-1][j-1]+1;
				}else dp[i][j] = -1;
			}
		}
	}

	// for(int i=0;i<=len1;i++){
	// 	for(int j=0;j<=len2;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	int m = -1;
	int *ans = new int[len1];
	int count_ans = 0;
	char *returnans = new char[len1+1];
	int count = 0;
	for(int i=1;i<=len1;i++)
		if(dp[i][len2]>m){
			m = dp[i][len2];
			count_ans = 0;
			ans[count_ans++] = i-m;
		}else if(dp[i][len2]!=-1 && dp[i][len2]==m){
			ans[count_ans++] = i-m;
		}

	if(count_ans!=0){
		int len = ans[0];
		for(int i = 0;i<m;i++){
			cout<<input[i+ans[0]];
			returnans[count++] = input[i+ans[0]];
		}
		for(int j =1;j<count_ans;j++){
			returnans[count++] = ' ';
			len = ans[j];
			for(int i =0;i<m;i++){
				returnans[count++] = input[i+ans[j]];
			}
		}
		
	
		cout<<endl;
		returnans[count++] = '\0';

}
	return returnans;


}

int main(){
	char input[] = "acddagd";
	char rule[] = "a?d";
	cout<<my_find(input,rule)<<endl;
	return 0;
}