#include "stdafx.h"
#include "CompareString.h"

void compareStringMain(){
	//volientCompareStringSample();
	//sortCompareStringSample();
	//countSortCompareStringSample();
	//hashCompareStringSample();
	primeCompareStringSample();

}

void primeCompareStringSample(){
	string a = "abcdefg";
	string b = "abc";
	bool result =primeCompareString(a,b);
	if(result)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}

bool primeCompareString(string &longStr,string &shortStr){
	int primeNum[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,
		61,67,71,73,79,83,89,97,101};
	int longProduct = 1;

	for(int i=0;i<longStr.length();i++){
		int index = longStr[i] - 'a';
		longProduct *= primeNum[index];
	}

	bool isContain = true;
	for(int i=0;i<shortStr.length();i++){
		int index = shortStr[i] - 'a';
		if(longProduct%primeNum[index]!=0){
			isContain = false;
			break;
		}
			
	}

	return isContain;


}

void hashCompareStringSample(){
	string a = "abcdefg";
	string b = "abc";
	bool result =hashCompareString(a,b);
	if(result)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}

bool hashCompareString(string &longStr,string &shortStr){
	int hashTable[26] = {0};
	int num = 0;

	for(int i=0;i<shortStr.length();i++){
		int index = shortStr[i]-'a';
		if (hashTable[index]==0){
			hashTable[index] = 1;
			num++;
		}
			
	}

	for(int i=0;i<longStr.length();i++){
		int index = longStr[i] - 'a';

		if(hashTable[index]==1){
			hashTable[index]=0;
			num--;
			if(num==0)
				break;
		}
	}

	if(num==0)
		return true;
	else
		return false;
}

void countSortCompareStringSample(){
	string a = "abcdefg";
	string b = "abc";
	string longsStr = a;
	string shortStr = b;
	countSort(a,longsStr);
	countSort(b,shortStr);
	bool result =countSortCompare(a,b);
	if(result)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}

void countSort(string &str,string &help_str){
	int help[26] = {0};

	for(int i=0;i<str.length();i++){
		int index = str[i] - 'a';
		help[index] += 1;
	}

	for(int i=1;i<26;i++){
		help[i] += help[i-1];
	}

	for(int i=0;i<str.length();i++ ){
		int index = str[i] -'a';
		help[help[index]-1] = str[i];
		help[index] -= 1;
	}
}

bool countSortCompare(string &longStr,string &shortStr){
	int longPosition = 0;
	int shortPosition = 0;
	bool isContain = true;
	while(longPosition<longStr.length() && shortPosition <shortStr.length()){
		while(longStr[longPosition]<shortStr[shortPosition] && longPosition<longStr.length()-1)
			longPosition++;

		while(shortStr[shortPosition] == shortStr[shortPosition + 1])
			shortPosition++;
		
		if(longStr[longPosition] != shortStr[shortPosition]){
			isContain = false;
			break;
		}

		longPosition++;
		shortPosition++;
	}
	return isContain;

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
			//strLongPostion++;
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