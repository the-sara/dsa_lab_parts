using namespace std;

#include <iostream>
#include <string>
//first task :
struct arraylist{
    #define max 6;
    int size;
   std::string arrelements[max];
};
struct ptrnode{
    string element ;
    ptrnode * next ;
};

class array_list_class {
    arraylist arrlist;
    public:
    void init(arraylist &l){l.size=0;}
    bool isempty(arraylist l ){if (l.size==0) {return true}
                                else {return false }}
    int sizeof(arraylist l){return l.size;l}
    void insert (arrlist &l,string value ,int pos ){
        if(l.size==max){cout<<"it is full";}
        else if (pos>l.size){ cout <<"you cant ";}
        else {
            for (int i=l.size,i>p;i++){
                arrelement[i]=arrelement[i-1];
            }
            l.element[pos]=value;
            l.size++;
        }
    }
    void deleting(pos){
        if(l.size==0){cout<<"it is empty";}
        else if (pos>l.size){ cout <<"you cant ";}
        else {
            for (int i=p,i>l.size-1;i++){
                arrelement[i]=arrelement[i+1];
            }
            l.size--;
        }
    }
    int search (arrlist & l,string value ){
        if(l.size==0){cout<<"it is empty";}
        else {
            for(int i=0;i<l.size;i++){
                if (l.arrelement[i]==value){return i;}
                else return -1;
            }
        }
    }

    string traverse ( arrlist& l ){
        if(l.size==0){cout<<"it is empty";}
        else {
            for (int i=0;i<l.size;i++){
                cout<< arrelement[i];
            }
        }
    }

    string traverse_backward(arrlist& l ){
        if(l.size==0){cout<<"it is empty";}
        else {
            for (int i=l.size;i>0;i++){
                cout<< arrelement[i];
            }
        }
    }
}

class linked_list_class {
    ptrnode * head;
    public:
    void init(inked_list_class l){head=NULL;}
    bool isempty(inked_list_class l ){
        if (head==NULL){cout <<"list is empty ";return true;}
        else{return false ;}
    }
    int sizeof(inked_list_class l){
        ptrnode temp=head;
        int count =0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count ;
    }
    void insert (linked_list_classl l,string value ,int pos  ){
        ptrnode *v= new ptrnode ;
        v->element=value;
        if (head == NULL){ 
            if (pos!=0){cout<< "no";}
            else {
                head =v;
                head->next=NULL;
            }
        else {
            if (pos=0){//inserting in the front 
                v->next=head ;
                head=v;
            }
            else{
                ptrnode temp=head ;
                int j=0;
                while (temp!NULL && j<pos-1){
                    temp=temp->next;
                    j++;
                }
                v->next=temp->next->next;
                temp->next=v;

            }
        }

        }
    }
    void deleting(pos){StringNode* v, *t=head;
        if(head==NULL)
            cout<<"Empty list"<<endl;
        else{
            if(i==0){
                v=head;
                head=head->next;
                delete v;
            }
            else{
                unsigned j=0;
                while(t!=NULL && j<i-1){
                    t=t->next;
                    j++;
                }
                if(t==NULL || t->next==NULL)
                    cout<<"Bad position"<<endl;
                else{
                    v=t->next;
                    t->next=v->next;
                    delete v;
                }
            }
        }
        
    }
    int search (inked_list_class & l,string value ){
        if (head ==NULL){return -1;cout<<"list is empty ";}
        else { 
            ptrnode temp=head;
            int i =0;
            while(temp!=NULL){
                if (temp.element ==value){
                    return i;}
                temp=temp->next;
                i++;}
            return -1;
        }
    }
    string traverse ( linked_list_class& l ){
        if (head==NULL){ rerturn "list is empty ";}
        ptrnode temp=head;
        while(temp!=NULL){
            temp=temp->next;
    }
    void backward(StringNode * cur){
        if (cur!=NULL){
            backward(cur->next);
            cout<< cur->elem <<" ";
        }
    }
    
    string traverse_backward(inked_list_class& l ){
        if (head==NULL)
            cout<<"Empty list"<<endl;
        else{
            cout<<"[";
            backward(head);
            cout<<"]"<<endl;
}

    }
}
//theaplication : a list for storing the names of the students according to their grades average 
//using array 
class student {
    string name ;
    float grade ;
}
class grade_list {
    //the attributes :
    private :
    int size ;
    int max_size ;
    arrlist l ;
    public:
    grade_list(int the_max){
        max_size=the_max;
        size=0;
        l=new arrlist[the_max];//allocation 
    }
    ~ grade_list (){delete l;}
    //the methodes 
    void add (student s ){
        if (isempty)

    }
}



