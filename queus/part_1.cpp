//part one of the quies implementation lab :
//statrt witht the headers :
#include<iostream>
using namespace std;
typedef int elem;
//we strt with tthe code :
//first we d othe parent function :
class parentqueue {
    //the buplic methode definition "
public:
        bool isEmpty();
        int size();
        void enqueue(elem e);
        void dequeue();
        elem front();
        void printing();
};
//the inheritance :
//first the array implementation :

namespace arrQueue{
class queue:public parentqueue{
    //the private attributes for the array implemetation:
private :
    int capacity  ;//the max size
    int n ;//the actual size 
    int f,r;//the importnat indexes 
    elem* arr; //declaring the arrray pointer 
    //now the methodes for the array implementation :
public :
    //the constructor : we allocate the arrays and make the queue empty :
    queue(int cap){
        capacity=cap;
        f=r=-1;
        n=0;
        // we allocate the array :
        arr= new elem[cap];
    }
    //the destructor : we deallocate 
    ~queue(){
        delete [] arr;
    }
    //the methodes :
    bool isEmpty(){
        return (n==0);
    }
    int size (){return n;}
    void enqueue(elem e ){
        //adding at the rear with the incrementation of everything 
        if (n==capacity){ throw "the array queue is full ";}
        else{
        arr[r]= e ;
        r=(r+1)%capacity;
        n++;}
    }
    void dequeue(){
        // decrementation of everything in the array 
        //seeing if its empty :
        if (n==0){throw "the array queue is empty ";}
        else{
            f=(f-1)%capacity;
            n--;
        }
    }
    elem front(){
        if (n==0){throw "the array queue is empty ";}
        else{return arr[f];}
    }
    void printing (){
        cout<<"printing the array content ";
        for (int i=0;i<n;i++){
            cout <<arr[i];
        }
    }

};//ened of the array implementation class 

}

namespace ptrQueue{
//the linked list implemnetation= pointer implementation :
//the node struct :
struct node{
    elem element ;
    node* next;
};


class queue :public parentqueue{
    //the private attributes :
private:
    node*  f;
    node* r;
    int n;//the number of the nodes 
public :
    //the constructor and the destructor :
    queue(){
        //make the list empty:
        f=r=NULL;
        n=0;
    }
    ~queue(){
        //destroting delelting all the nodes :
        //we need to traverse and delete node by node :
        node* temp=f;//f is the head 
        //traversing using the while loop:
        while (temp!=NULL){
            node*tempnode =temp->next;
            delete temp;
            temp=tempnode;
            n=0;
        }
    } 
    bool isEmpty(){
        return (f==NULL);
    }
    int size(){return n;}
    void enqueue(elem e){
        node* newnode=new node ;
        newnode->element=e;
        if (isEmpty()){
            //so we will only have the new node :
            r=f=newnode;}
        else{
        r->next=newnode;
        r=newnode;//r always points to the new element 
        n++;
    }}
    void dequeue(){
        //we rmove from the front so we remove and update the f :
        if(isEmpty()){throw "this queueu is empty"; }
        else{
            node* tempnode=f;
            f=f->next;
            delete tempnode;

        }
    }
//printing we nedd to traverse and output :
void printing (){
    //creating a new node to traverse :
    node* temp=f;
    while(temp!=NULL){
        //traversing :
        temp=temp->next;
        cout<<temp->element;
    }
}
};
}

int main(){

    arrQueue::queue q1(12);
    ptrQueue::queue q2;
    return 0;
}