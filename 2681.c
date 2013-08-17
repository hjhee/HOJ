#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int c,l,r,lazy;
    struct node *left,*right;
}node, *pnode;

void traverse(pnode tree){
    if(tree!=NULL){
        traverse(tree->left);
        printf("(%d, %d, %d, %d)\n", tree->l, tree->r, tree->c, tree->lazy);
        traverse(tree->right);
    }
}

void init(pnode *tree, int l, int r){
    *tree=(pnode)malloc(sizeof(node));
    (*tree)->l=l;
    (*tree)->r=r;
    (*tree)->c=0;
    (*tree)->lazy=0;
    if(r==l)
        (*tree)->left=(*tree)->right=NULL;
    else{
        if((r+l)/2-l>=0)
            init(&((*tree)->left), l, (l+r)/2);
        else
            (*tree)->left=NULL;
        if(r-(l+r)/2>=1)
            init(&((*tree)->right), (l+r)/2+1, r);
        else
            (*tree)->right=NULL;
    }
}

void colour(pnode tree, int l, int r, int c){
    /*
    printf("[%d, %d, %d]->[%d, %d, %d, %d]\n", l, r, c,
            tree->l, tree->r, tree->c, tree->lazy);
            */
    if(l>r)
        return;
    if(tree->l==tree->r){
        if(tree->l>=l&&tree->r<=r)
            tree->c=c;
    }else if(!(tree->l>r||tree->r<l)){
        if(l<=tree->l&&tree->r<=r){
            tree->lazy=1;
            tree->c=c;
        }else{
            if(tree->lazy==1){
                tree->lazy=0;
                    colour(tree->left, tree->l, l-1, tree->c);
                    colour(tree->right, tree->l, l-1, tree->c);
                    colour(tree->left, r+1, tree->r, tree->c);
                    colour(tree->right, r+1, tree->r, tree->c);
            }
            if(tree->l>l)
                l=tree->l;
            if(tree->r<r)
                r=tree->r;
            colour(tree->left, l, r, c);
            colour(tree->right, l, r, c);
        }
    }
}

int stat(pnode tree, int l, int r, int c){
    /*
    printf("[%d, %d, %d]->[%d, %d, %d, %d]\n", l, r, c,
            tree->l, tree->r, tree->c, tree->lazy);
            */
    if(l>r)
        return 0;
    if(tree->l==tree->r){
        if(tree->l>=l&&tree->r<=r)
            return tree->c==c;
    }else if(!(tree->l>r||tree->r<l)){
        if(tree->lazy==1){
            if(l<tree->l)
                l=tree->l;
            if(r>tree->r)
                r=tree->r;
            return (r-l+1)*(tree->c==c);
        }else
            return stat(tree->left, l, r, c)+stat(tree->right, l, r, c);
    }
    return 0;
}

void delete_tree(pnode tree){
    if(tree->left!=NULL)
        delete_tree(tree->left);
    if(tree->right!=NULL)
        delete_tree(tree->right);
    free(tree);
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("2681.in", "rb", stdin);
#endif
    int n,m,x,y,c;
    pnode segment;
    while(scanf("%d%d", &n, &m)==2){
        init(&segment, 1, n);
        /*
        traverse(segment);
        puts("---------");
        */
        while(m--){
            scanf("%d%d%d", &x, &y, &c);
            colour(segment, x, y, c);
            /*
            traverse(segment);
            puts("---------");
            */
        }
        /* traverse(segment); */
        printf("%d\n", stat(segment, 1, n, 0));
        delete_tree(segment);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}
