#include <stdio.h>

char E1[20010],E2[20010];

int main(void){
	int n,c,e,k,i,tmp,key;
	while(scanf("%s%s", E1, E2)!=EOF){
		n=strlen(E1)>>1;
		for(c=32,k=0; k<n; ++k){
			tmp=(E2[(k<<1)]>'9'?E2[(k<<1)]-55:E2[(k<<1)]-'0')*16+(E2[(k<<1)+1]>'9'?E2[(k<<1)+1]-55:E2[(k<<1)+1]-'0');
			key=tmp^c;
			printf("%02X", key);
			tmp=(E1[(k<<1)]>'9'?E1[(k<<1)]-55:E1[(k<<1)]-'0')*16+(E1[(k<<1)+1]>'9'?E1[(k<<1)+1]-55:E1[(k<<1)+1]-'0');
			c=tmp^key;
		}
		tmp=(E2[(k<<1)]>'9'?E2[(k<<1)]-55:E2[(k<<1)]-'0')*16+(E2[(k<<1)+1]>'9'?E2[(k<<1)+1]-55:E2[(k<<1)+1]-'0');
		key=tmp^c;
		printf("%02X\n", key);
	}
	return 0;
}