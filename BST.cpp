#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
 int data;
 struct node *left;
 struct node *right;
} node;
node *root,*child;
class BST
{
   public:

       void insert(int );
       void display(node *);
       void inorder(node *);
       void preorder(node *);
       void postorder(node *);
       void delete_node(node *,int );
       node* find_node(node *,int);
       //void delete_node(node *,int);
       void delete_0(node *,node *);
       void delete_1(node *,node *);
       void delete_2(node *,node *);
};
int main()
{
    int choice,x;
    BST bst;
    while(1)
    {


        cout<<"1.Insert element ";
        cout<<"2.Display BST ";
        cout<<"3.Inorder Traversal ";
        cout<<"4.Preorder Traversal"<<endl ;
        cout<<"5.Postorder Traversal ";
        cout<<"6.Delete element ";
        cout<<"7.Exit"<<endl;
        cin>>choice;

       switch(choice)
       {
        case 1:
           cout<<"Enter the Number you want to insert :";
           cin>>x;
           bst.insert(x);
           break;

       case 2:
           bst.display(root);
            break;
       case 3:
           bst.inorder(root);
           break;
       case 4:
           bst.preorder(root);
           break;
       case 5:
           bst.postorder(root);
       case 6:
           cout<<"Enter element to be deleted :";
           cin>>x;
           bst.delete_node(root,x);
           break;
       case 7:
            exit(1);
       default:
           cout<<"Wrong Choice"<<endl;
      }
    }
    return 0;
}

void BST::display(node *root1)
{
    if(root1==NULL)
        return;
    cout<<root1->data<<endl;
    display(root1->left);
    display(root1->right);
}
void BST::insert(int x)
{
    node *temp=new node,*temp1,*prev;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
        return ;
    }
    temp1=root;
    while(temp1!=NULL)
    {
        prev=temp1;
        if(temp1->data==x)
        {
            cout<<"Element is already in the tree"<<endl;
            return;
        }
        if(temp1->data>x)
            temp1=temp1->left;
        else
            temp1=temp1->right;
    }
    if(prev->data>x)
        prev->left=temp;
    else
        prev->right=temp;

}
void BST::inorder(node *root1)
{
    if(root1==NULL)
        return;

    inorder(root1->left);
    cout<<root1->data<<endl;
    inorder(root1->right);

}
void BST::postorder(node *root1)
{
    if(root1==NULL)
        return;
    postorder(root1->left);
    postorder(root1->right);
    cout<<root1->data<<endl;
}
void BST::preorder(node *root1)
{
    if(root1==NULL)
        return;
    cout<<root1->data<<endl;
    preorder(root1->left);
    preorder(root1->right);
}
void BST::delete_node(node *root1,int x)
{
   node *parent=find_node(root1,x);
   if(child==NULL)
   {
       cout<<"No such element found"<<endl;
       return;
   }
   if(child->left==NULL&&child->right==NULL);
      delete_0(child,parent);
}

void BST::delete_0(node *child,node *parent)
{
    if((parent->left)->data==child->data)
        parent->left=NULL;
    else
        parent->right=NULL;
    delete child;
    child=NULL;
    cout<<"Node deleted\n";

}
void BST::delete_1(node *child,node *parent)
{
    node *temp;
    if(child->left==NULL)
        temp=child->right;
    else
        temp=child->left;
    if(parent->data==child->data)
    {
        parent->data=temp->data;
        delete temp;
        parent->left=NULL;
        parent->right=NULL;
        return;
    }
    if((parent->left)->data==child->data)
        parent->left=temp;
    else
        parent->right=temp;
    delete child;
    cout<<"Node deleted\n";
}
node* BST::find_node(node *p,int x)
{
    node *parent;
    if(p==NULL)
    {
        cout<<"Your BST is empty\n";
        return NULL;
    }
    parent=p;
    while(p!=NULL&&p->data!=x)
    {
        parent=p;
        if(p->data>x)
        {
            p=p->left;
        }
        else
        {
            p=p->right;
        }
    }
    child=p;
    return parent;

}
void BST::delete_2(node* child,node* parent )
{
    node *temp=child->right,*prev=child,*curr;
    while(temp->left!=NULL)
    {
        prev=temp;
        temp=temp->left;
    }
    if(prev->right!=temp)
    {
        temp->right=child->right;
        temp->left=child->left;

    }
    else
    {
        temp->right=NULL;
        temp->left=child->left;
    }
    if(parent->data!=child->data)
    {
        if((parent->left)->data==child->data&&parent->left!=NULL)
            parent->left=temp;
        else
            parent->right=temp;
    }
     return ;
}
