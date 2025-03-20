#include<stdio.h>
#include<iostream>
//concatenating two linked lists :
//the struct :
struct node{
    int elem;
    node* next;
};

//the function :
node* concate(node* l1,node* l2){
    //we got the heads of the two nodes 
    //so we just need to traverse the first list and put the last node to point to the head of the second list 
     //travesing the fist list :'
     node* temp=l1;//cus we never lose the head 
     while(temp!=NULL){
        temp=temp->next;
     }
     //temp takes the value of the last one so here temp=last node 
     temp=l2;
     return l1;
}