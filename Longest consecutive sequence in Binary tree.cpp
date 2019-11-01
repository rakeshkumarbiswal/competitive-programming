int max1;

int LongestConsecutive(Node* root)
{
    int path=0;
     if(root==NULL)
     return path;
     path++;
     Node* temp=root;
     while(temp!=NULL&&((temp->left!=NULL&&temp->data+1==temp->left->data)||(temp->right!=NULL&&temp->data+1==temp->right->data)))
     {
         path++;
         if(temp->left!=NULL&&temp->data+1==temp->left->data)
         {
             temp=temp->left;
         }
         if(temp->right!=NULL&&temp->data+1==temp->right->data)
         {
             temp=temp->right;
         }
     }
     if(path>max1)
     max1=path;
     int pp=LongestConsecutive(root->left);
     if(pp>max1)
     max1=pp;
     pp=LongestConsecutive(root->right);
     if(pp>max1)
     max1=pp;
     return max1;
}

int longestConsecutive(Node* root)
{
     max1=-99;
     int p= LongestConsecutive(root);
     if(p!=1)
     return p;
     return -1;
}
