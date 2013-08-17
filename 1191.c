#include <stdio.h>

int next_permutation(char *s){
	int i,j;
	static int base[26];
	for(i=0; i<26; ++i)
		base[i]=0;
	for(i=0; s[i]!='\n'&&s[i]!='\0'; ++i);
	for(i-=2; i>-1&&s[i]>=s[i+1]; --i)
		++base[s[i+1]-'a'];
	if(i<=-1)
		return 0;
	++base[s[i]-'a'];
	++base[s[i+1]-'a'];
	for(j=s[i]-'a'+1; j<26&&!base[j]; ++j);
	if(j==26)
		return 0;
	s[i++]=j+'a';
	--base[j];
	for(j=0; j<26; ++j)
		while(base[j]){
			s[i++]=j+'a';
			--base[j];
		}
	s[i++]='\0';
	return 1;
}

int main(void){
	char string[100];
	while(fgets(string, 100, stdin)!=NULL&&*string!='#'){
		if(next_permutation(string))
			puts(string);
		else
			puts("No Successor");
	}
	return 0;
}
