#include<iostream>
#include<string>

using namespace std ;
typedef int elem;

// the node struct :
struct node {
    int key;
    elem data ;
    node* left ;
    node* right;
    int height ;
node(int k)
        : key(k), data(k), left(nullptr), right(nullptr), height(1) {};
};

// the class :
class avl {
public:
        node* root ;
        avl(int val);
        int getheight(node* n);
        int getbalance(node* n);
        void totalbalance(node* root);
        node* search(node* root ,int k );
        node* rightrotate(node* n);
        node* leftrotate(node* n);
        node* insert(node* root,int k);
        node* deleting(int k ,node* root ); 
        void inorder(node* root);
};
//constructor:
avl::avl(int val) : root(new node(val)) {};


//getheight 
int avl::getheight(node* n){
        if (n==NULL){return 0;}
        else{
        return n->height;}
}

//getbalance:
int avl:: getbalance(node* n){
        // claculate and return the balance factor of the node 
        int bf;
        bf=getheight(n->left)-getheight(n->right);
        return bf;        
}

//totalbalance:
void avl:: totalbalance(node* root){
        // traverse and get the balance 
        //base case :
        if (root==NULL){return;}
        else{
                totalbalance(root->left);
                cout<<getbalance(root);
                totalbalance(root->right);
        }
}

//search:
node* avl:: search(node* root ,int k ){
        if(root==NULL || root->key==k){return root;}
        else{
                if(k< root->key){return search(root->left,k);}
                if(k> root->key){return search(root->right,k);}
        }
}

//left rotation:
node* avl:: leftrotate(node* n){
        node* new_root= n->right;
        n->right=new_root ->left;
        new_root->left=n;
        n->height = 1 + max(getheight(n->left), getheight(n->right));
        new_root->height = 1 + max(getheight(new_root->left), getheight(new_root->right));
        return new_root;
}

//right rotation:
node* avl::rightrotate(node* n ){
        node* new_node = n->left;
        n->left = new_node->right;
        new_node->right = n;
        n->height = 1 + max(getheight(n->left), getheight(n->right));
        new_node->height = 1 + max(getheight(new_node->left), getheight(new_node->right));
        return new_node;
            }


// insertion :
node* avl::insert(node* root,int k ){
        node* curr=root;
        //base case:
        if (curr==NULL){
            // we insert as a leaf :
            return new node (k);
        }
        else{
            if (k<curr->key){
                curr->left=insert(curr->left,k);}
            else if(k>curr->key) {curr->right=insert (curr->right,k);}
            else{ return root;}
            
                curr->height = 1 + max(getheight(curr->left), getheight(curr->right));
                // we check all the nodes moving from the newly inserted node upwardly :
                int balance =getbalance(curr);

                if (balance>1 && getbalance(curr->left)>=0){
                    return rightrotate(curr );}
                if (balance<-1 && getbalance(curr->right)<=0){
                    return leftrotate(curr);}
                if (balance>1 && getbalance(curr->left)<0){
                    curr->left=leftrotate(curr->left);
                    return rightrotate(curr); }
                if (balance<-1 && getbalance(curr->right)>0){
                    curr->right=rightrotate(curr->right);
                    return leftrotate(curr);}
                return curr;// if balanced 
                }}

//deletion:
node* avl:: deleting(int k ,node* root ){
// we use recursion :
node* curr= root ;
if (curr==NULL){ return NULL;}
if (k<curr->key){ curr->left= deleting(k,curr->left);}
else if (k>curr->key){ curr->right= deleting(k,curr->right);}
else{
        // case1: it is a leaf so we delelete it directely :
        if (curr->left==NULL && curr->right ==NULL){
                delete curr;
                return NULL;
        }
        // case 2 :it got one child :
        if (curr->left ==NULL && curr->right!=NULL){// it has the right
            node* temp1=curr->right;
            delete curr;
            return temp1;  
        }
        if (curr->right ==NULL && curr->left!=NULL){// it has the left
                node* temp2=curr->left;
                delete curr;
                return temp2;  
        }
        // case3: it got 2 childs:
        if (curr->left !=NULL && curr->right!=NULL){
                // we  get the min in the right subtree:
                node* rightchild=curr->right;
                while(rightchild->left!=NULL){
                        rightchild=rightchild->left;
                }
                // replace their keys :
                curr->key=rightchild->key;
                curr->right=deleting(rightchild->key,curr->right);
        }}
curr->height = 1 + max(getheight(curr->left), getheight(curr->right));
int balance =getbalance(curr);
                if (balance>1 && getbalance(curr->left)>=0){
                        return rightrotate(curr );}
                if (balance<-1 && getbalance(curr->right)<=0){
                        return leftrotate(curr);}
                if (balance>1 && getbalance(curr->left)<0){
                        curr->left=leftrotate(curr->left);
                        return rightrotate(curr);}
                if (balance<-1 && getbalance(curr->right)>0){
                        curr->right=rightrotate(curr->right);
                        return leftrotate(curr);}
return curr;// if balanced 
}

//inorder traversal:
void avl:: inorder(node* root){
        if (root==NULL){return; }
       inorder(root->left);
       cout<< root->key <<" ";
       inorder(root->right);
               }


// the main :
int main(){
    // instatiation:
    avl tree=avl(10);

    //insertion:
        tree.root= tree.insert(tree.root,20);
        tree.root= tree.insert(tree.root,30);
        tree.root= tree.insert(tree.root,8);
        tree.root= tree.insert(tree.root,7);
        tree.root= tree.insert(tree.root,15);
        tree.root= tree.insert(tree.root,13);
        tree.root= tree.insert(tree.root,12);
        tree.root= tree.insert(tree.root,31);
        tree.root= tree.insert(tree.root,11);

    cout<<"\n result of insertion \n";
    tree.inorder(tree.root);

    //deletion
    tree.deleting(31,tree.root);
    cout<<"\n result of deletion \n";
    tree.inorder(tree.root);

    //searching:
    cout<< "\n result of searching\n";
    if (tree.search(tree.root,30)!=NULL){cout<<"key found";}
    else{cout<<"key not found";}

    cout<< "\n balance checking \n";
    //checking balance :
    tree.totalbalance(tree.root);

    cout<< "\n getting height \n";
    int h=tree.getheight(tree.root);
    cout<<h;
    
}