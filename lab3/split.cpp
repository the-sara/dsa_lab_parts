#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
    int elem;
    node* next;
};
//the split function of the indexes :
void splitOddEven(node* l,node* e,node* o){
    node* temp=l;
    for(int i ;temp!=NULL;i++){
        temp=temp->next;//traversing;
        if (i%2==0){e->next=temp;}
        else{o->next=temp;}

    }
}