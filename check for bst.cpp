int tr;
int pre;
void inorder(Node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    if(root->data<pre)
    tr=0;
    pre=root->data;
    if(tr)
    inorder(root->right);
    
}
bool isBST(Node* root) {
    tr=1;
    pre=-1;
    inorder(root);
    if(tr)
    return 1;
    return 0;
}
