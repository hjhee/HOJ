#include <stdio.h>
#define OUTPUT_PILE { \
	fputs("maxpile: ", stdout); \
	for(i=1; i<=n; ++i) \
		printf("%d ", maxpile[i]); \
	putchar('\n'); \
	fputs("minpile: ", stdout); \
	for(i=1; i<=n; ++i) \
		printf("%d ", minpile[i]); \
	putchar('\n'); \
}

int mtop,Mtop;
unsigned long long maxpile[65536],minpile[65536];

void init_pile(void){
	Mtop=mtop=0;
}

void max_bubbleup(int t){
	unsigned long long swap;
	while(t>1&&maxpile[t]>maxpile[t>>1]){
		swap=maxpile[t>>1];
		maxpile[t>>1]=maxpile[t];
		maxpile[t]=swap;
		t>>=1;
	}
}

void min_bubbleup(int t){
	unsigned long long swap;
	while(t>1&&minpile[t]<minpile[t>>1]){
		swap=minpile[t>>1];
		minpile[t>>1]=minpile[t];
		minpile[t]=swap;
		t>>=1;
	}
}

void max_bubbledown(int t){
	int p;
	unsigned long long max;
	while((t<<1)<=Mtop){
		p=t<<1;
		max=maxpile[p];
		if(p+1<=Mtop&&max<maxpile[p+1]){
			++p;
			max=maxpile[p];
		}
		if(maxpile[t]<maxpile[p]){
			maxpile[p]=maxpile[t];
			maxpile[t]=max;
			t=p;
		}else
			break;
	}
}

void min_bubbledown(int t){
	int p;
	unsigned long long min;
	while((t<<1)<=mtop){
		p=t<<1;
		min=minpile[p];
		if(p+1<=mtop&&min>minpile[p+1]){
			++p;
			min=minpile[p];
		}
		if(minpile[t]>minpile[p]){
			minpile[p]=minpile[t];
			minpile[t]=min;
			t=p;
		}else
			break;
	}
}

void insert_maxpile(int x){
	maxpile[++Mtop]=x;
	max_bubbleup(Mtop);
}

void insert_minpile(int x){
	minpile[++mtop]=x;
	min_bubbleup(mtop);
}

unsigned long long delete_maxpile(void){
	unsigned long long value;
	value=maxpile[1];
	maxpile[1]=maxpile[Mtop--];
	max_bubbledown(1);
	return value;
}

unsigned long long delete_minpile(void){
	unsigned long long value;
	value=minpile[1];
	minpile[1]=minpile[mtop--];
	min_bubbledown(1);
	return value;
}

int main(void){
	int n,i,tmp;
	unsigned long long a,b,min,max;
	while(scanf("%d", &n), n){
		init_pile();
		for(i=0; i<n; ++i){
			scanf("%d", &tmp);
			insert_maxpile(tmp);
			insert_minpile(tmp);
		}
		while(1){
			a=delete_maxpile();
			if(Mtop==0){
				min=a;
				break;
			}else{
				b=delete_maxpile();
				insert_maxpile(a*b+1);
			}
		}
		while(1){
			a=delete_minpile();
			if(mtop==0){
				max=a;
				break;
			}else{
				b=delete_minpile();
				insert_minpile(a*b+1);
			}
		}
		printf("%llu\n", max-min);
	}
	return 0;
}
