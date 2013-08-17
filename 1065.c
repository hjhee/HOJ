#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000

typedef struct node{
    struct node *left,*right;
    int freq;
    char c;
}node;

char text[N+10];

int cmp_node(const void *a, const void *b){
    return (*(node **)b)->freq-(*(node **)a)->freq;
}

int traverse(node *f, int l){
    if(f==NULL)
        return 0;
    /*
    printf("%c: (%d, %d)\n", f->c, f->freq, l);
    */
    if(f->left!=NULL||f->right!=NULL)
        return traverse(f->left, l+1)+traverse(f->right, l+1);
    return l*f->freq;
}

int compress(char *text, int len){
    int i,hlen,num;
    node encode[27]={{0}},*list[27],*tmp;
    for(i=0; i<27; ++i){
        list[i]=encode+i;
        encode[i].c=i+'A';
    }
    encode[26].c='_';
    for(i=0; i<len; ++i){
        if(text[i]=='_')
            ++encode[26].freq;
        else
            ++encode[text[i]-'A'].freq;
    }
    for(num=-1, i=0; i<27; ++i)
        if(encode[i].freq)
            ++num;
    /*
    for(i=0; i<27; ++i)
        printf("%c: %d\n", list[i]->c, list[i]->freq);
    */
    qsort(list, 27, sizeof(node *), cmp_node);
    if(num==0)
        return list[0]->freq;
    while(num>0){
        qsort(list, num+1, sizeof(node *), cmp_node);
        /*
        for(i=0; i<=num; ++i)
            printf("%c: %d\n", list[i]->c==0?'*':list[i]->c, list[i]->freq);
        */
        tmp=(node *)malloc(sizeof(node));
        tmp->left=list[num-1];
        tmp->right=list[num];
        tmp->freq=tmp->left->freq+tmp->right->freq;
        tmp->c=0;
        list[num-1]=tmp;
        --num;
    }
    hlen=traverse(list[0], 0);
    return hlen;
}

int main(void){
    int len,hlen;
    while(1){
        scanf("%s", text);
        if(text[0]=='E'&&text[1]=='N'&&text[2]=='D'&&text[3]=='\0')
            break;
        len=strlen(text);
        hlen=compress(text, len);
        len=len*8;
        printf("%d %d %.1f\n", len, hlen, ((double)len)/hlen);
    }
    return 0;
}
