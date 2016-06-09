#include<bits/stdc++.h>
using namespace std;
struct node
{
 int val;
 struct node *left;
 struct node *right;
 struct node *parent;
};
#define p parent
#define l left
#define r right
node *root,*child;
class BST
{
    /*private
        node *root;*/
    public:
        /*BST() {
            root=NULL;
        }*/
        node* tree_maximum(node *);
        node* tree_minimum(node *);
        node* tree_search(node *,int );
        node* tree_successor(node *);
        node* tree_predecessor(node *);
        void tree_insert(int );
        void display(node *);
        void inorder(node *);
        void preorder(node *);
        void postorder(node *);
        void delete_node(node *,int );
        node* find_node(node *,int);

        void delete_0(node *);
        void delete_1(node *);
        void delete_2(node *);

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
           bst.tree_insert(x);
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
           break;
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
node* BST::tree_search(node *root1,int x) {
    if(root1==NULL) {
        return NULL;
    }
    if(x==root1->val)
        return root1;
    else if(x>root1->val) {
        return (tree_search(root1->right,x));
    }
    return(tree_search(root1->left,x));
}
node* BST::tree_maximum(node *root1) {
    if(root1==NULL) {
        return NULL;
    }
    if(root1->right==NULL) {
        return(root1);
    }
    return tree_maximum(root1->right);
}
node* BST::tree_minimum(node *root1) {
    if(root1==NULL) {
        return NULL;
    }
    if(root1->left==NULL) {
        return(root1);
    }
    return tree_minimum(root1->left);
}
node* BST::tree_successor(node *root1) {
    if(root1->right!=NULL)
        return (tree_minimum(root1->right));
    node *temp=root1->p;
    // temp=NULL that means no successor i.e. given node has highest value
    while(temp->p!=NULL&&temp->right==root1) {
        root1=temp;
        temp=root1->p;
    }
    return temp;


}
node* BST::tree_predecessor(node *root1){
    if(root1->left!=NULL)
        return tree_maximum(root1->left);
    node *temp=root1->p;
    while(temp->p!=NULL&&temp->left==root1) {
        root1=temp;
        temp=root1->p;
    }
    return temp;
}
void BST::display(node *root1)
{
    if(root1==NULL)
        return;
    cout<<root1->val<<endl;
    display(root1->left);
    display(root1->right);
}
void BST::tree_insert(int x)
{
    node *temp=new node,*temp1,*prev;
    temp->val=x;
    temp->left=NULL;
    temp->right=NULL;
    temp->p=NULL;
    if(root==NULL)
    {
        root=temp;
        root->p=NULL;
        return ;
    }
    temp1=root;
    while(temp1!=NULL)
    {
        prev=temp1;
        if(temp1->val==x)
        {
            cout<<"Element is already in the tree"<<endl;
            return;
        }
        if(temp1->val>x)
            temp1=temp1->left;
        else
            temp1=temp1->right;
    }
    if(prev->val>x)
        prev->left=temp;
    else
        prev->right=temp;
    temp->p=prev;
    cout<<"Node Inserted\n";

}
void BST::inorder(node *root1)
{
    if(root1==NULL)
        return;

    inorder(root1->left);
    cout<<root1->val<<endl;
    inorder(root1->right);

}
void BST::postorder(node *root1)
{
    if(root1==NULL)
        return;
    postorder(root1->left);
    postorder(root1->right);
    cout<<root1->val<<endl;
}
void BST::preorder(node *root1)
{
    if(root1==NULL)
        return;
    cout<<root1->val<<endl;
    preorder(root1->left);
    preorder(root1->right);
}

void BST::delete_node(node *root1,int x)
{
    node *curr=tree_search(root1,x);
    if(curr==NULL)
    {
        cout<<"No such element found"<<endl;
        return;
    }
    if(curr->left==NULL&&curr->right==NULL)
        delete_0(curr);
    else if(curr->left!=NULL&&curr->right==NULL||curr->right!=NULL&&curr->left==NULL)
        delete_1(curr);
    else
        delete_2(curr);

}

void BST::delete_0(node *curr) {
    node *par=curr->p;
    if(curr->p==NULL)
        root=NULL;

    else if(par->left==curr)
        par->left=NULL;
    else
        par->right=NULL;
    delete curr;
    cout<<"Node deleted\n";
}
void BST::delete_1(node *curr)
{
    node *par=curr->p,*temp;

    if(curr->left!=NULL)
        temp=curr->left;
    else if(curr->right!=NULL)
        temp=curr->right;
    if(root==curr)
        root=temp;
    if(par==NULL)
        temp->p=par;

    else if(curr==par->left)
        par->left=temp;
    else if(curr==par->right)
        par->right=temp;
    temp->p=par;

    delete curr;
    cout<<"Node deleted\n";
}

void BST::delete_2(node* curr)  {
    node *succ=tree_successor(curr);
    //cout<<succ->val<<endl;
    node *par=curr->p;


    if(root==curr)
        root=succ;
    if(succ==curr->right) {

        if(par!=NULL) {

            if(par->left==curr)
                par->left=succ;
            else
                par->right=succ;
        }
        succ->left=curr->left;
        (curr->left)->p=succ;
        (curr->right)->p=succ;


    }
    else {


        (succ->p)->left=succ->right;
        if(succ->right!=NULL)
            (succ->right)->p=succ->p;
        succ->right=curr->right;
        succ->left=curr->left;
        (curr->left)->p=succ;
        (curr->right)->p=succ;
        if(par!=NULL) {

            if(par->left==curr)
                par->left=succ;
            else
                par->right=succ;
        }


    }

    succ->p=par;
    delete curr;
    cout<<"Node deleted\n";

}
