/*This is a function problem.You only need to complete the function given below*/
/* Structure for tree and linked list
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
// This function should convert a given Binary tree to Doubly
// Linked List
Node *convert(Node *root,char v)
{
    
    if(root==NULL)
    return root;
    
    else if(root->left==NULL&&root->right==NULL)
    return root;
    
    else if(root->left!=NULL&&root->right==NULL)
    {
        root->left=convert(root->left,'l');
        root->left->right=root;
        Node *temp;
        if(v=='r')
        {
            temp=root;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            return temp;
        }
        else
        {
            temp=root;
            while(temp->right!=NULL)
            temp=temp->right;
            return temp;
        }
    }
    
    else if(root->right!=NULL&&root->left==NULL)
    {
        
        root->right=convert(root->right,'r');
        root->right->left=root;
        Node *temp;
        if(v=='r')
        {
            temp=root;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            return temp;
        }
        else
        {
            temp=root;
            while(temp->right!=NULL)
            temp=temp->right;
            return temp;
        }
    }
    
    else if(root->right!=NULL&&root->left!=NULL)
    {
        
        root->left=convert(root->left,'l');
        root->left->right=root;
        root->right=convert(root->right,'r');
        root->right->left=root;
        Node *temp;
        
        if(v=='r')
        {
            temp=root;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            return temp;
        }
        else
        {
            temp=root;
            while(temp->right!=NULL)
            temp=temp->right;
            return temp;
        }
    }
}
void bToDLL(Node *root, Node **head_ref)
{
    Node *temp=root;
    while(temp->left!=NULL)
    temp=temp->left;
    *head_ref=temp;
    convert(root,'l');
}
