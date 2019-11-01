#include<queue>
void leftView(Node *root)
{
   queue<Node*>q;
   q.push(root);
   cout<<root->data<<" ";
   while(!q.empty())
   {
       q.push(NULL);
       while(q.front()!=NULL)
       {
           Node *temp=q.front();
           if(temp->left!=NULL)
           q.push(temp->left);
           if(temp->right!=NULL)
           q.push(temp->right);
           q.pop();
       }
       if(q.front()==NULL)
       {
           q.pop();
           if(!q.empty())
           cout<<(q.front()->data)<<" ";
       }
   }
}
