stack<node*>s,s1;
stack<char>ss,ss1;
bool find_parent_list(node* root,node* target)
{
    if(root==NULL)
    return false;
    if(root==target)
    return true;
    bool l=find_parent_list(root->left,target);
    if(l)
    ss.push('L');
    bool r=find_parent_list(root->right,target);
    if(r)
    ss.push('R');
    if(l||r)
    s.push(root);
}
/* Prints all nodes at distance k from a given target node.
 The k distant nodes may be upward or downward.  This function
 Returns distance of root from target node, it returns -1 if target
 node is not present in tree rooted with root. */
void funct(node* root,int k)
{
    if(root==NULL)
    return;
    if(k<0)
    return;
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    funct(root->left,k-1);
    funct(root->right,k-1);
}
int printkdistanceNode(node* root, node* target , int k)
{
    while(!s.empty())
    s.pop();
    bool p=find_parent_list(root,target);
    while(!s.empty())
    {
        s1.push(s.top());
        s.pop();
        ss1.push(ss.top());
        ss.pop();
    }
    if(p==1)
    funct(target,k);
    if(p==1)
    {
       // cout<<s1.top()->data<<" ";
        while(!s1.empty())
        {
            if(ss1.top()=='L')
            {
                s1.top()->left=NULL;
                ss1.pop();
            }
            else if(ss1.top()=='R')
            {
                s1.top()->right=NULL;
                ss1.pop();
            }
            funct(s1.top(),--k);
            s1.pop();
        }
    }
    
    if(p==0)
    return -1;
    return 0;
}