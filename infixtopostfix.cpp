#include <iostream>
#include <stack>
#include <string>

typedef int elem;
using namespace std;//to not use the string ::

class arrstack {
    //attributes :
private :
    elem t;
    elem capacity ;
    elem* element;//pointer 
public:
    //constructor and destructor :
    arrstack(int cap);
    ~arrstack();
    //methodes 
    bool isEmpty();
    elem getsize();
    void puch (int e );
    elem pop();
    elem top();
    void traverse();
    int precedency(char op);
    string infixtopostfix(string infix);
};
//methodes bodyies :
arrstack:: arrstack(int cap ){
    capacity=cap;
    element=new elem[capacity];
    t=-1;//initialize the stack to be empty 
}
arrstack::~arrstack (){
    delete [] element;
}
bool arrstack::isEmpty(){
    return (t<0);
}
void arrstack::puch (elem e ){
    if (t==capacity-1) {cout << "stack is full";}
    else{
    t++;
    element[t]=e;
}}
elem arrstack ::  pop (){
    if (isEmpty()){cout<<"stack is embpty";return 0;}
    else {
        elem elming=element[t];
        t--;
        return elming ;
    }
}
elem arrstack :: top(){
    if (isEmpty()){throw "stack is empty";}
    else {
        return element[t--];
    }
}
arrstack:: traverse(){
    if (isEmpty()){cout<<"stack is empty ";}
    else {
        for (int i =0;i<=t;i++){
            cout << element[i]<<endl;
        }
    }}
int arrstack:: getsize(){return t+1;}


int arrstack:: precedency(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/'|| op=='^') return 2;
    return 0;
}
string arrstack:: infixtopostfix(string infix){
arrstack st(10); // so we can work with it //just a variable 
string postfix="" ;//both the input and the output are strings 
// we need input infix which is array ,
//we need stack st 
//we need the output postfix 
//the algo:inside a for loop cus we read the infix (input )charachter one by one  :
for (int i =0;i<infix.length();i++){
    // 1 if the character is '(' we puch to stack :
    if (infix[i]=='('){st.puch(infix[i]);}
    //if the char is operand (0-->9)//we append to output 
    else if (infix[i]>='0' && infix[i]<='9'){  //isalphanum
        postfix.append(1,infix[i]);
    }
    //if the char is an operation 
    //-->we check the precendency with the top of the stack 
    //if there is not puch that operator in our stack 
    //if there is pop them and append to the output (postfix)and puch our operator 
    else if {
        while(precedency(st.top())>=precedency(infix[i]) && !st.isEmpty()){
            postfix.append (1,st.pop());
            //st.puch(infix[i]);
        }
        st.puch(infix[i]);
    }
    else{
        int arr_list[10]=st.traverse();
        for (int k=0;k<10;k++){
            while (arr_list[k]!='('){postfix.append(arr_list[k]);}
        }
    }
    int arr_list[10]=st.traverse();
        for (int k=0;k<10;k++){postfix.append(arr_list[k]);}
    //cout<< "the postfix rsult is";
    return postfix; 
}

}
//the mian :
int main(){
    //instantiation:
    arrstack my_stack(10);
    string outpp;
    outpp=my_stack.infixtopostfix("(4+6)+3+37");
    cout << outpp;
}