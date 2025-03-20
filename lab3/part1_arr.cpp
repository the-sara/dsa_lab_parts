//creatin the stack using array implementation :
#include <iostream>
using namespace std;

class arrstack {
    //attributes :
private :
    int t;
    int capacity ;
    int* element;//pointer 
public:
    //constructor and destructor :
    arrstack(int cap);
    ~arrstack();
    //methodes 
    bool isEmpty();
    int getsize();
    void puch (int e );
    void pop();
    int top();
    void traverse();
};
//methodes bodyies :
arrstack:: arrstack(int cap ){
    capacity=cap;
    element=new int[capacity];
    t=-1;//initialize the stack to be empty 
}
arrstack::~arrstack (){
    delete [] element;
}
bool arrstack::isEmpty(){
    return (t<0);
}
void arrstack::puch (int e ){
    if (t==capacity-1) {cout << "stack is full";}
    else{
    t++;
    element[t]=e;
}}
void arrstack ::  pop (){
    if (isEmpty()){cout<<"stack is embpty";}
    else {
        t--;
    }
}
int arrstack :: top(){
    if (isEmpty()){throw "stack is empty";}
    else {
        return element[t--];
    }
}
void arrstack:: traverse(){
    if (isEmpty()){cout<<"stack is empty ";}
    else {
        for (int i =0;i<=t;i++){
            cout << element[i]<<endl;
        }
    }}
int arrstack:: getsize(){return t+1;}

//the main :
int main(){
    //instantiation:
    arrstack my_arrstack(10);
    int choice ;
    //the menue:
    while(choice!=0){
    cout<<"menue: chooose a number ";
    cin>>choice;
    switch (choice){
        case 1:
            cout<<my_arrstack.isEmpty();
            break;
        case 2:
            my_arrstack.getsize();
            break;
        case 3:
            cout<<"enter a number ";
            int number;
            cin>>number;
            my_arrstack.puch(number );
            break;
        case 4:
            my_arrstack.pop();
            break;
        case 5:
            my_arrstack.top();
            break;
        case 6:
            my_arrstack.traverse();
            break;
    }}
return 0;
}