#include <iostream>
using namespace std;

int StrToInt(const char* str){
	bool negative = false;
	long long result = 0;
	while(*str == ' ' || *str == '\t')
	{
		++str;
	}
	if(*str == '-')
	{
		negative = true;
		++str;
	}
	else if(*str == '+'){
		++str;
	}

	while(*str!='\0'){
		int n = *str - '0';
		if(n<0 || n>9){
			break;
		}
		if(negative){
			result = result *10 -n;
			if(result < -2147483638LL){
				result = -2147483638LL;
			}
		}
		else{
			result = result *10 +n;
			if(result > 2147483647LL){
				result = 2147483647LL;
			}
		}
		++str;
	}
	return result;
}

int main(){
	char str[] = "-123456";
	cout<<StrToInt(str);
	return 0;
}