#include <iostream>
using namespace std;

#define N 5
int map[5][5] ={
	{2,0,8,0,2},
	{0,0,0,0,0},
	{0,3,2,0,0},
	{0,0,0,0,0},
	{2,0,8,0,2}
};
int sumMax=0;
int p1x=0;
int p2x=0;
int p1y=0;
int p2y=0;
int curMax = 0;

void dfs(int index){
	if(index == N*2-2){
		if (curMax>sumMax){
			sumMax = curMax;
		}
		return;
	}

	if(!(p1x==0 && p1y == 0) && !(p2x==N-1 && p2y == N-1))
	{
		if(p1x>=p2x && p1y>=p2y){
			return;
		}
	}

	if(p1x+1<N && p2x+1<N){
		p1x++;p2x++;
		int sum = map[p1x][p1y]+map[p2x][p2y];
		curMax+=sum;
		dfs(index+1);
		curMax-=sum;
		p1x--;p2x--;
	}
	if(p1x+1<N && p2y+1<N){
		p1x++;p2y++;
		int sum = map[p1x][p1y]+map[p2x][p2y];
		curMax+=sum;
		dfs(index+1);
		curMax-=sum;
		p1x--;p2y--;
	}
	if(p1y+1<N && p2x+1<N){
		p1y++;p2x++;
		int sum = map[p1x][p1y]+map[p2x][p2y];
		curMax+=sum;
		dfs(index+1);
		curMax-=sum;
		p1y--;p2x--;
	}
	if(p1y+1<N && p2y+1<N){
		p1y++;p2y++;
		int sum = map[p1x][p1y]+map[p2x][p2y];
		curMax+=sum;
		dfs(index+1);
		curMax-=sum;
		p1y--;p2y--;
	}
	return;
}

int main(){
	curMax = map[0][0];
	dfs(0);
	cout<<sumMax-map[N-1][N-1]<<endl;
	return 0;
}
