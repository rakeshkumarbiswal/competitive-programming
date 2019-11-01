#include<queue>
void connect(Node *p)
{
    queue<Node *>q;
    q.push(p);
    Node *curr,*next;
    while(!q.empty())
    {
        q.push(NULL);
        while(q.front()!=NULL)
        {
            curr=q.front();
            q.pop();
            next=q.front();
            curr->nextRight=next;
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);
        }
        q.pop();
    }
}
