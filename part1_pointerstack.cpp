//creatin the stack using pointer implementation :
#include <iostream>
using namespace std;

struct node{
    int elem;
    node*next;
};

class linkedstack {
    //attributes :
private :
    node* t;
    int capacity ;
public:
    //constructor and destructor :
    linkedstack(int cap);
    ~linkedstack();
    //methodes 
    bool isEmpty();
    int getsize();
    void puch (int e );
    void pop();
    int top();
    void traverse();
};
//methodes bodyies :
linkedstack:: linkedstack(int cap ){
    capacity=cap;
    t=NULL;//initialize the stack to be empty 
}
linkedstack::~linkedstack (){}
bool linkedstack::isEmpty(){
    return (t==NULL);
}
void linkedstack::puch (int e ){
        node* newnode=new node;
        newnode->next=t;
        newnode=t;
        t->elem=e;
        capacity++;
        }
void linkedstack ::  pop (){
    if (isEmpty()){cout<<"stack is embpty";}
    else {
        t ->next=t;
        delete t;
    }
}
int linkedstack :: top(){
    if (isEmpty()){throw "stack is empty";}
    else {
        return t->elem;
    }
}
void linkedstack:: traverse(){
    if (isEmpty()){cout<<"stack is empty ";}
    else {
        node* temp=t;
        while(temp!=NULL){
            cout<<t->elem;
            temp=temp->next;
        }
        }
    }
int linkedstack:: getsize(){
    if (isEmpty()){return 0;
                    cout<<"stack is empty ";}
    else {
        int count;
        node* temp=t;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
        }
}

//the main :
int main(){
    //instantiation:
     int choice ;
     bool ret1;
     int ret2;
     int ret3;
    linkedstack my_linkedstack(10);
    //the menue:
    while (choice != 0){
    cout<<"menue: chooose a number ";
    cin>>choice;
    switch (choice){
        case 1:
            my_linkedstack.isEmpty();
            break;
        case 2:
            my_linkedstack.getsize();
            break;
        case 3:
            cout<<"enter a number ";
            int number;
            cin>>number;
            my_linkedstack.puch(number );
            break;
        case 4:
            my_linkedstack.pop();
            break;
        case 5:
        cout<< my_linkedstack.top();
            break;
        case 6:
            my_linkedstack.traverse();
            break;
        case 0:
          cout<<"exiting programm";
            break;
    } }
return 0;
}//creatin the stack using pointer implementation :
#include <iostream>
using namespace std;

struct node{
    int elem;
    node*next;
};

class linkedstack {
    //attributes :
private :
    node* t;
    int capacity ;
public:
    //constructor and destructor :
    linkedstack(int cap);
    ~linkedstack();
    //methodes 
    bool isEmpty();
    int getsize();
    void puch (int e );
    void pop();
    int top();
    void traverse();
};
//methodes bodyies :
linkedstack:: linkedstack(int cap ){
    capacity=cap;
    t=NULL;//initialize the stack to be empty 
}
linkedstack::~linkedstack (){}
bool linkedstack::isEmpty(){
    return (t==NULL);
}
void linkedstack::puch (int e ){
        node* newnode=new node;
        newnode->next=t;
        newnode=t;
        t->elem=e;
        capacity++;
        }
void linkedstack ::  pop (){
    if (isEmpty()){cout<<"stack is embpty";}
    else {
        t ->next=t;
        delete t;
    }
}
int linkedstack :: top(){
    if (isEmpty()){throw "stack is empty";}
    else {
        return t->elem;
    }
}
void linkedstack:: traverse(){
    if (isEmpty()){cout<<"stack is empty ";}
    else {
        node* temp=t;
        while(temp!=NULL){
            cout<<t->elem;
            temp=temp->next;
        }
        }
    }
int linkedstack:: getsize(){
    if (isEmpty()){return 0;
                    cout<<"stack is empty ";}
    else {
        int count;
        node* temp=t;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
        }
}

//the main :
int main(){
    //instantiation:
     int choice ;
     bool ret1;
     int ret2;
     int ret3;
    linkedstack my_linkedstack(10);
    //the menue:
    while (choice != 0){
    cout<<"menue: chooose a number ";
    cin>>choice;
    switch (choice){
        case 1:
            my_linkedstack.isEmpty();
            break;
        case 2:
            my_linkedstack.getsize();
            break;
        case 3:
            cout<<"enter a number ";
            int number;
            cin>>number;
            my_linkedstack.puch(number );
            break;
        case 4:
            my_linkedstack.pop();
            break;
        case 5:
        cout<< my_linkedstack.top();
            break;
        case 6:
            my_linkedstack.traverse();
            break;
        case 0:
          cout<<"exiting programm";
            break;
    } }
return 0;
}