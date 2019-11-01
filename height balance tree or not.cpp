bool tr;
int max(int x,int y)
{
    if(x>y)
    return x;
    return y;
}
int height(Node *root)
{
    if(root==NULL)
    return -1;
    int x=height(root->left);
    int y=height(root->right);
    if(x-y>1||y-x>1)
    tr=0;
    return max(x,y)+1;
}
bool isBalanced(Node *root)
{
    tr=1;
    height(root);
    return tr;
}
