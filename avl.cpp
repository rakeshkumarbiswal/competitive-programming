#include<iostream>
using namespace std;
struct avl
{
    int data;
    struct avl *leftchild;
    struct avl *rightchild;
    struct avl *parent;
    int balance;
};

void findavl(struct avl *root,int data,struct avl **insertpos)
{
    if(root==NULL)
    {
        return ;
    }
    *insertpos=root;
    if(root->data<data)
    {
        findavl(root->right,data,insertpos);
    }
    else
    {
        findavl(root->left,data,insertpos);
    }

}
struct avl * newnode(int data)
{
    struct avl *temp=new(sizeof(struct avl));
    temp->data=data;
    temp->leftchild=NULL;
    temp->rightchild=NULL;
    temp->parent=NULL;
    temp->balance=0;
}
void insertinto(struct avl *root,int data)
{
    struct avl *insertpos;
    findavl(root,data,&insertpos);
    struct avl *temp=newnode(data);
    if(root==NULL)
    {
        root=temp;
        return ;
    }
    if(data<insertpos->data)
    {
        insertpos->left=temp;
        temp->parent=insertpos;
    }
    else
    {
        insertpos->right=temp;
        temp->parent=insertpos;
    }
}
int main()
{

}
