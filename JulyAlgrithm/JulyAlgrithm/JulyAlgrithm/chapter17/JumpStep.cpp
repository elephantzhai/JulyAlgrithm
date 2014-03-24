#include <iostream>
using namespace std;


long long Fabonacci_Sloution1(unsigned int n){
	if(n<2){
		return n;
	}

	return Fabonacci_Sloution1(n-1) + Fabonacci_Sloution1(n-2);
}

int main(){
	cout<<Fabonacci_Sloution1(10);
	return 0;
}

