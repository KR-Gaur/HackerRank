#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* nextRight;
    Node(int x){
        data = x;
        left = right = NULL;
        nextRight = NULL;
    }
};
void connect(struct Node *p);
void printSpecial(Node *root)
{
   if (root == NULL)
     return;
   Node *node = root;
   while (node != NULL)
   {
      printf("%d ", node->data);
      node = node->nextRight;
   }
   if (root->left)
     printSpecial(root->left);
   else
     printSpecial(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     connect(root);
     printSpecial(root);
     printf("");
     inorder(root);
     printf("");
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */
// Should set the nextRight for all nodes
#include<queue>
void connect(Node *p)
{
   queue<struct Node*> q;
   //p->nextRight = NULL;
   q.push(p);
   int m=1,n=0;
   struct Node *temp=NULL;
   while(!q.empty()){
      
       while(m!=0){
        temp = q.front();
        if(m-1<=0) temp ->nextRight = NULL;
        else    temp ->nextRight = q.front();
        
        if(temp->left!=NULL)    {q.push(temp->left);n++;}
        if(temp->right!=NULL)   {q.push(temp->right);n++;}
        
        q.pop(); 
        m--;
       }
       temp->nextRight =NULL;
       while(n!=0){
        temp = q.front();
        if(n-1<=0) temp ->nextRight = NULL;
        else    temp ->nextRight = q.front();
        
        if(temp->left!=NULL)    {q.push(temp->left);m++;}
        if(temp->right!=NULL)   {q.push(temp->right);m++;}
        
        q.pop(); 
        n--;
       }
       temp->nextRight =NULL;
       
   }
}

