#include "stdafx.h"
#include "CompareString.h"

void compareStringMain(){
	volientCompareStringSample();

}

void volientCompareStringSample(){
	string a = "abcdefg";
	string b = "abc";

	bool result = volientCompareString(a,b);
	if(result)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}

bool volientCompareString(string &longStr,string &shortStr){
	bool isContain = true ;
	for(int j=0;j<shortStr.length();j++ ){
		bool charContian = false;
		for(int i = 0;i<longStr.length();i++){
			if(longStr[i]==shortStr[j]){
				charContian = true;
				break;
			}
		}
		if(!charContian){
			isContain = false;
			break;
		}
	}
	return isContain;
}