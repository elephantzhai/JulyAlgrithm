#include <iostream>
#include <list>
using namespace std;

list<int> list1;

void find_facetor(int sum,int n){
	if(n<=0 || sum<= 0)
		return;

	if(sum == n){
		list1.reverse();
		for(list<int>::iterator iter = list1.begin();iter != list1.end();iter++)
			cout<<*iter<<"+";
		cout<<n<<endl;
		list1.reverse();
	}
	list1.push_front(n);
	find_facetor(sum-n,n-1);
	list1.pop_front();
	find_facetor(sum,n-1);
}

int main(){
	int sum,n;
	sum = 6;
	n = 3;
	find_facetor(sum,n);
	return 0;
}