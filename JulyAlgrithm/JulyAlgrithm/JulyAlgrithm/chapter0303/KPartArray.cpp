#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int num,data;
	bool operator <(const node &p)const
	{
		return data < p.data;
	}

};

node p[100001];
int array[7]={1,5,2,6,3,7,4};

int main(){
   int n=7;
   int i,j,a,b,c;//c:flag

   a=1,b=4,c=3;//2-5中第3小的

   for(int i=0;i<n;i++){
   	p[i].data = array[i];
   	p[i].num = i;
   }
   

   sort(p,p+n);

   for(i=0;i<n;i++){
   	if(p[i].num>=a && p[i].num<=b){
   		c--;
   	}
   	if(c==0)
   		break;
   }

   cout<<p[i].data;

   return 0;
}
