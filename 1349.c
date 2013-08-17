#include <stdio.h>
#define N 50

typedef struct{
    int d,f,i;
}pool;

int z;
pool p[64+10];

void pop_up(int t){
    int u;
    pool max;
    u=t>>1;
    if(u<1)
        return;
    if((p[u].f<p[t].f)||(p[u].f==p[t].f&&p[u].i>p[t].i)){
        max=p[t];
        p[t]=p[u];
        p[u]=max;
        pop_up(u);
    }
}

void pop_down(int t){
    int u,w;
    pool max;
    u=t<<1;
    if(u>z)
        return;
    max=p[t];
    w=t;
    if(max.f<p[u].f||(max.f==p[u].f&&max.i>p[u].i)){
        max=p[u];
        w=u;
    }
    if(u+1<=z&&(p[u+1].f>max.f||(p[u+1].f==max.f&&p[u+1].i<max.i))){
        max=p[u+1];
        w=u+1;
    }
    if(w!=t){
        p[w]=p[t];
        p[t]=max;
        pop_down(w);
    }
}

void insert_pile(pool l){
    p[++z]=l;
    pop_up(z);
}

pool max_pile(void){
    pool l;
    l=p[1];
    p[1]=p[z--];
    pop_down(1);
    return l;
}

void list_pile(void){
	int i;
	putchar('\n');
	puts("--------");
	for(i=1; i<=z; ++i)
		printf("%d ", p[i].f);
	putchar('\n');
	puts("--------");
}

int fish(int h, int n, pool *l, int *t, int *dt){
    int i,f;
    pool q;
    for(h*=60, i=1; i<=n; ++i)
        h-=5*t[i];
    for(i=0; i<=n; ++i)
        dt[i]=0;
    for(z=i=0; i<=n; ++i)
        insert_pile(l[i]);
    for(f=0, q=max_pile(); h>=5&&q.f>0; q=max_pile()){
        h-=5;
        f+=q.f;
        ++dt[q.i];
        q.f-=q.d;
        insert_pile(q);
#ifdef DEBUG
	printf("(%d, %d, %d) ", q.i, q.f, q.d);
	list_pile();
#endif
    }
    return f;
}

int main(void){
    int n,i,j,h,l,max,tmp,test,t[N],time[N],dt[N];
    pool lake[50];
    for(test=0; scanf("%d", &n)==1&&n; ++test){
	if(test)
	    putchar('\n');
        scanf("%d", &h);
        for(i=0; i<n; ++i){
            lake[i].i=i;
            scanf("%d", &lake[i].f);
        }
	for(i=0; i<n; ++i)
	    scanf("%d", &lake[i].d);
        for(t[0]=0, i=1; i<n; ++i)
            scanf("%d", t+i);
        for(max=-1, i=0; i<n; ++i){
            tmp=fish(h, i, lake, t, dt);
            if(max<tmp){
                max=tmp;
                for(l=i, j=0; j<=i; ++j)
                    time[j]=dt[j];
            }
        }
        for(j=i=0; i<=l; ++i){
		time[i]*=5;
		j+=time[i]+5*t[i];
	}
	for(; i<n; ++i)
		time[i]=0;
	time[0]+=h*60-j;
	for(i=0; i<n-1; ++i)
            printf("%d, ", time[i]);
	printf("%d\n", time[n-1]);
        printf("Number of fish expected: %d\n", max);
    }
    return 0;
}
