#include <iostream>
using namespace std;

int a[5][5] ={
		{2,0,8,0,2},
		{0,0,0,0,0},
		{0,3,2,0,0},
		{0,0,0,0,0},
		{2,0,8,0,2}
	};
const int N = 202;
const int inf = 1000000000;
int dp[2][N][N];
bool isValid(int step,int x1,int x2,int n){
	int y1 = step - x1;
	int y2 = step - x2;
	return ((x1>=0) && (x1<n) && (x2>=0) && (x2<n) && (y1>=0) && (y1<n) && (y2>=0) && (y2<n));
}
int getValue(int step,int x1,int x2,int n){
	return isValid(step,x1,x2,n)?dp[step%2][x1][x2]:(-inf);
}



int getAnswer(int n){
	int p = 2*n - 2;
	int i,j,step,s;
	for(i = 0;i<n;++i){
		for(j = i;j<n;++j){
			dp[0][i][j] = -inf;
		}
	}
	dp[0][0][0] = a[0][0];

	for(step = 1;step<=p;step++){
		for(int i=0;i<n;i++){
			for(int j = i;j<n;j++){
				s = step%2;
				dp[s][i][j] = -inf;
				if(!isValid(step,i,j,n)){
					continue;
				}

				if(i!=j){
					dp[s][i][j] = max(dp[s][i][j],getValue(step-1,i-1,j,n));
					dp[s][i][j] = max(dp[s][i][j],getValue(step-1,i,j-1,n));
					dp[s][i][j] = max(dp[s][i][j],getValue(step-1,i-1,j-1,n));
					dp[s][i][j]+= a[i][step-i] + a[j][step-j];

				}else{
					dp[s][i][j] = max(dp[s][i][j],getValue(step-1,i-1,j,n));
					dp[s][i][j] = max(dp[s][i][j],getValue(step-1,i,j-1,n));
					dp[s][i][j] = max(dp[s][i][j],getValue(step-1,i-1,j-1,n));
					dp[s][i][j]+= a[i][step-i];
				}
			}
		}
	}
	return dp[p%2][n-1][n-1];

}

int main(){
	cout<<getAnswer(5);
	return 0;
}