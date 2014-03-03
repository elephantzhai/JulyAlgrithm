#include <iostream>
using namespace std;

int main(){
	int array[] = {1,2,3,-4,5,-3,6,-9,5};
	int n = 9;

	int sum=0,b=0;

	for(int i=0;i<n;i++){
		if(b<0){
			b = array[i];
		}else{
			b += array[i];
		}

		if(b>sum)
			sum = b;
	}

	cout<<sum<<endl;
}