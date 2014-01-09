#include "stdafx.h"
#include "CompareString.h"

void compareStringMain(){
	//volientCompareStringSample();
	sortCompareStringSample();


}
void sortCompareStringSample(){
	string a = "abcdefg";
	string b = "abc";
	quickSort(a,0,a.length()-1);
	quickSort(b,0,b.length()-1);
	bool result =sortCompareString(a,b);
	if(result)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;

}

void quickSort(string &str,int lo,int hi){
	if(lo<hi){
		int mid = partition(str,lo,hi);
		quickSort(str,lo,mid-1);
		quickSort(str,mid+1,hi);
	}
}

int partition(string &str,int lo,int hi){
	char key = str[hi];
	int i = lo-1;

	for(int j=0;j<hi;j++){
		if(str[j]<=key){
			i++;
			swap(str[i],str[j]);
		}
	}
	swap(str[hi],str[i+1]);
	return i+1;
}

bool sortCompareString(string &longStr,string &shortStr){
	int strLongPostion = 0;
	int strShortPostion = 0;
	bool isContain = true;
	while(strLongPostion<longStr.length() && strShortPostion<shortStr.length()){
		while(longStr[strLongPostion]<shortStr[strShortPostion] && strLongPostion<longStr.length()-1)
			strLongPostion++;
		if(longStr[strLongPostion]!=shortStr[strShortPostion]){
			isContain = false;
			break;
		}else{
			strLongPostion++;
			strShortPostion++;
		}
	}
	return isContain;
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