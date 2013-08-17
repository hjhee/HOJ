typedef int ElementType;

typedef struct node{
    struct node *ch[2];
    struct node *pre;
    ElementType key;
}node, *pnode;

ElementType splay_find(pnode tree, ElementType x){
    if(tree==NULL)
        return;
    if(tree->key==x)
        return x;
    if(tree->key>x)
        return splay_find(tree->left, x);
    else
        return splay_find(tree->right, x);
}

pnode splay_rotate(pnode tree, int direction){
}

void splay_insert(pnode tree){
}
