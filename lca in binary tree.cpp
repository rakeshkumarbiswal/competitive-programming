bool search(Node *root,int key)
{
    if(root==NULL)
    return false;
    if(root->data==key)
    return true;
    bool p=search(root->left,key);
    bool q=search(root->right,key);
    return p||q;
}
Node * lca(Node* root ,int n1 ,int n2 )
{
    if(root->data==n1||root->data==n2)
    return root;
    bool p=search(root->left,n1);
    bool q=search(root->right,n2);
    if(p&q)
    return root;
    if(p==true&&q==false)
    {
        return lca(root->left,n1,n2);
    }
    if(q==true&&p==false)
    {
        return lca(root->right,n1,n2);
    }
    if(p==false&&q==false)
    {
        return lca(root,n2,n1);
    }
}
