#include <iostream>
using namespace std;
#define Len 0x500
#define nTableSize 0x500

typedef struct 
{
	/* data */
	int nHashA;
	int nHashB;
	char bExists;
}SOMESTRUCTRE;

int cryptTable[Len];

void prepareCryptTable(){
	unsigned long seed = 0x00100001,index1 = 0,index2 = 0,i;
	for(index1 = 0;index1 <0x100;index1++){
		for(index2 = index1,i=0;i<5;i++,index2+=0x1){
			unsigned long temp1,temp2;

			seed = (seed *125+3)%0x2AAAAB;
			temp1 = (seed & 0xFFFF)<<0x10;

			seed = (seed *125+3)%0x2AAAAB;
			temp2 = (seed & 0xFFFF);

			cryptTable[index2] = (temp1 | temp2);
		}
	}
}
unsigned long HashString(const char *lpszkeyName,unsigned long dwHashType){
	unsigned char *key = (unsigned char *)lpszkeyName;
	unsigned long seed1 = 0x7FED7FED;
	unsigned long seed2 = 0xEEEEEEEE;
	int ch;
	while(*key != 0){
		ch = *key++;
		seed1 = cryptTable[(dwHashType<<8)+ch]^(seed1+seed2);
		seed2 = ch+seed1+seed2+(seed2<<5)+3;
	}
	return seed1;
}

int GetHashTablePos(char *lpszString,SOMESTRUCTRE *lpTable){
	int nHash = HashString(lpszString);
	int nHashPos = nHash % nTableSize;
}

int main(){
	prepareCryptTable();
	for(int i=0;i<Len/12;i++){
		cout<<cryptTable[i]<<" ";
	}
	return 0;
}