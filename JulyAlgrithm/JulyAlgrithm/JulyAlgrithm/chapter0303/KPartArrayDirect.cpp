#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int data,num;
	bool operator < (const node &p) const{
		return data < p.data;
	}
};

node p[10001];
int array[7]={1,5,2,6,3,7,4};

int main(){
	int n = 7;
	int a=1,b=4,c=3;

	for(int i=0;i<n;i++){
		p[i].data = array[i];
		p[i].num = i;
	}

	sort(p+a,p+b+1);

	cout<<p[a+c-1].data;

	return 0;
}