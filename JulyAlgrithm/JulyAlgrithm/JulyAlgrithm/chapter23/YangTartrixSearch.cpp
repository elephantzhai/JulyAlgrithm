#include <iostream>
using namespace std;
#define row 4
#define col 4

void findYangMatrix(int a[][col],int findNum){
	int i=0,j=col-1;
	while(true){
		if(i>=row||j<0){
			cout<<"can't find"<<endl;
			return;
		}
		if(a[i][j]==findNum){
			cout<<"position:"<<i+1<<" "<<j+1;
			return;
		}
		if(findNum<a[i][j]){
			j--;
			continue;
		}
		if(findNum>a[i][j]){
			i++;
			continue;
		}
		cout<<"can't find"<<endl;
		return;
	}
	
	return;
}

int main(){
	int matrix[row][col] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int find = 6;
	findYangMatrix(matrix,find);
	return 0;
}