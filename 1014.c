#include <stdio.h>
#include <string.h>

int big_number[20000];
char number[20000];

int transform(int big_number[], char number[], int base){
	int i,j,tmp,len;
	for(i=j=tmp=0,len=strlen(number); i<len; ++i){
		tmp=tmp*base+number[i]-'0';
		if(tmp>=10){
			big_number[j++]=tmp/10;
			tmp%=10;
		}
	}
	return j;
}

void print(int big_number[], int len){
	int i;
	for(i=0; i<len; ++i)
		printf("%d", big_number[i]);
	printf("\n");
}

int divided(int big_number[], int len, int niven){
	int i,tmp;
	for(tmp=0,i=len-1; i>-1; --i){
		tmp=tmp*10+big_number[i];
		tmp%=niven;
	}
	return tmp;
}

int main(void){
	int base,i,niven,len;
	while(scanf("%d", &base)==1&&base){
		scanf("%s", number);
		len=strlen(number);
		for(i=0,niven=0; i<len; ++i)
			niven+=number[i]-'0';
		len=transform(big_number, number, base);
		print(big_number, len);
		printf("%s\n", divided(big_number, len, niven)?"no":"yes");
	}
	return 0;
}
