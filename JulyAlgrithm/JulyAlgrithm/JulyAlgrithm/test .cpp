#include <iostream>
using namespace std;

int main()
{
	int n = 10;
	int m = ((n>>1)-1)>=0?(n>>1)-1:0;
	cout<<m;
	return 0;
}