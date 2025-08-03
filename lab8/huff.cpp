#include <iostream>
#include <string>
#include <utility>
#include "heap_ds.cpp"
#include "bst_ds.cpp"

using namespace std;

class huffman{
public:
      void encodeing(heap_class heap);
}
void huffman:: encoding(heap_class heap){
    while(heap.size>1){
    // we delete two elements from the heap and insert them in the bst :
    pair<int,elem> left=heap.deleting();
    pair<int,elem> right=heap.deleting();
    bst.insert(bst.root,left);
    bst.insert(bst.root,right);
    // insert new node and make it its parent with its key the sum of theirs
    node* n= bst.insert(bst.root,(left.first + right.first));
    // we insert that node back into the heap 
    heap.insert(n->p);}
    bt.root=heap.deleting();// we have the whole tree

}
// preparing the input 
heap_class huffman::input(){
for (int i=0;i<10;i++){
    heap.insert(make_pair(1,a));
    heap.insert(make_pair(2,b));
    heap.insert(make_pair(3,c));
    heap.insert(make_pair(4,d));
    heap.insert(make_pair(5,e));
}
return heap;}

