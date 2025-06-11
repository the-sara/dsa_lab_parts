//implemetation of the avl tree data structure :
./// the avl tree impleemetation is based on the binary search tree implementaion
// e just need one extra parameter is the hight in th enode struct 
// the includation :
#include<iostream>
#include<string>

useing namespace std ;
// using the template 
typedef int elem;

// the node struct :
struct node {
    int key;
    elem data ;
    node* left ;
    node* right;
    int hight ;
};

// the class :
class avl {
private:
        node* root ;
public:
        //for the user interfacing :
        // constructor and destructor ;
        avl();// for the tree initiaization 
        int getHeight(node* n);
        int getbalance(node* n);
        rightRotate(y);
        leftRotate(x);
        void insert(int k);//we insert by the key 
        node* delete(int k ,node* root )
        node* serch(node* root ,int k );
        inOrderTraversal(node);

};
//constructor:
avl::avl(int val){
        node* root=new node;
        root->key=val;
        root->left=root->right=NULL;
        root->height=1;
}
//destructor:we delete all the nodes :
avl::~avl(){}
//getheight methode:
int getheight(node* n){
        return n->height;
}
int avl:: getbalance(node* n){
        // claculate and return the balance factor of the node 
        int bf;
        bf=getheight(n->left)-getheight(n->right);
        return bf;        
}
node* avl:: leftrotate(node* current){
        // to rebalace the heavy right of a node
        // we make the middle node the new subroot 
        // we make the left the of the midle node the right of the current node to maintain the bst 
        // we make the current node the left of the middle node 
        // than we adjust the height 
        node* new_root= currnt->right;// the middle node 
        // we adjut the pointers to the currnt node 
        currnt->right=new_root ->left;
        // we make the current the left node of the middle node 
        new_root->left=currnt;
        // we adjet the hight of the current and the new root 
        current.height = 1 + max(height(current->left), height(current->right));
        new_node.height = 1 + max(height(new_node->left), height(new_node->right));
        return new_root;
}

node* avl::rightrotate(node* current ){
        node* new_node = current->left;
        current->left = new_node->right;
        new_node->right = current;
        current.height = 1 + max(height(current->left), height(current->right));
        new_node.height = 1 + max(height(new_node->left), height(new_node->right));
        return new_node;
            }
// the insertion :
node* bst:: insert(node* root,int k ){
        // starting from the root using recursion
        node* curr=root;// already updated 
        //base case:
        if (curr==NULL){
            // we insert as a leaf :
            return new node (k);
        }
      
        else{
            if (key<= curr->k){
                curr->left=insert(curr->left,k);}
            else {curr->right=insert (curr->right,k);}
                current.height = 1 + max(height(current->left), height(current->right));
                // we check all the nodes moving from the newly inserted node upwardly :
                // we get the balance :
                int balance =getbalance(curr);
                // we got 4 cases :
                //1) the inserted is in the left left 
                //2) the inserted is in the right right 
                //3) the inserted is in the left riight 
                //4) the inserted is in the right left 

                if (balance>1 && k< curr->left->key){
                        return rightrotate(curr );
                }
                if (balance<-1 && k>curr->right->key){
                        return leftrotate(curr);
                }
                if (balance>1 && k>curr->left->key){
                        curr_left=leftrotate(curr->left);
                        return rightrotate(curr);
                }
                if (balance<-1 && k<curr->right->key){
                        curr->right=rightroatate(curr-right);
                        return leftroatate(curr);
                }
                return curr;// if balanced 
                }}
// the delete methode :
node* avl:: delete(int k ,node* root ){
// we use recursion :
// base case :
if (root==NULL){ return NULL;}
// the goal:
//  we need to search for the node first :
else{
if (k<curr->key){ curr->left= delete(k,curr->left);}
if (k>curr->key){ curr->right= delete(k,curr->right);}
// now we got the node :
// case1: it is a leaf so we delelete it directely :
if (curr->left==NULL && curr->right ==NULL){
        delete curr;
        return null;
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
// case3: it got childs:
if (curr->left !=NULL && curr->right!=NULL){
        // we  get the min in the right subtree:
        // we go to right one then we go left left left ...
        node* rightchild=curr->right;
        while(rightchild !=NULL){
                rightchild=rightchild->left;
        }
        // replace their keys :
        curr-key=rightchild->key;
        curr->right=delete(rightchild);
}
// the ortation same as the insertion:
current.height = 1 + max(height(current->left), height(current->right));
// we check all the nodes moving from the newly inserted node upwardly :
// we get the balance :
int balance =getbalance(curr);
// we got 4 cases :
//1) the inserted is in the left left 
//2) the inserted is in the right right 
//3) the inserted is in the left riight 
//4) the inserted is in the right left 

if (balance>1 && getbalance(curr->left)>=0){
        return rightrotate(curr );
}
if (balance<-1 && getbalance(curr->rigth)<=0){
        return leftrotate(curr);
}
if (balance>1 && getbalance(curr->left)<0){
        curr_left=leftrotate(curr->left);
        return rightrotate(curr);
}
if (balance<-1 && getbalance(curr->right)>0){
        curr->right=rightroatate(curr-right);
        return leftroatate(curr);
}
return curr;// if balanced 
}
node* avl:: search(node* root ,int k ){
        if(root==NULL || root->key==k){return root;}
        else{
                if(k< root->key){return search(curr->left);}
                if(k> root->key){return search(curr->right);}
        }
}

// in order traversal :
void avl:: inorder(node* root){
        // we use recursion :
        //left current right 
        if (root==NULL){return; }
        inorder(root->left);
        cout<< root->key;
        inorder(root->right);
}
        


