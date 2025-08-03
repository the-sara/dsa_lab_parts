//lab7:heap implementation:
#include<iostream>
#include<string>
using namespace std;

//implemeting the data structure :
//max heap:
class heap_calss{
private:
        //array ,size,capacity;
        int* arr;
        int size;
        int capacity;//for the allocation 
public:
       int peak();
       void insert(int k );
       void delete();//delete the root 
       void heapify();
       void heap_heapify(int* arr)
       int left(int i){return (2*i+1);}
       int right(int i){return (2*i+2);}
       int parent(int i){return (i-1)/2;}

}
//implemeting the methodes bodies :
//the constructor and destructor :
heap_class:: heap_class(int capacity){
/// allocate array with this capacity :
    arr=new int[capacity];//alocating the memeo 
    size=0;
}
~heap_calss(){
    delete[] arr;
}
//the peak methode :
int heap_class:: peak(){
    //return the root ;
    return arr[0];
}
void heap_class:: insert(int k ){
    //insert as a leaf then swap with the parent in a loop
    if (size==capacity){throw "error";}
    else{
        int i=size;
        arr[i]=k;
        size++
        //checking and swapping :
        while(i>=0 && (arr[i]>arr[parent(i)])){
            swap(arr[i],arr[parent_index])
            i=parent(i); }}
}
void heap_class:: delete(){
    //delete the root
    arr[0]=arr[size-1];
    size--;
    // than we heapify
    heapify(0);
}
void heap_class::heapify(int i){//swap parent with the better fit childe 
    int l=left(i);
    int r=right(i);
    int max=i;
    if (l<size && arr[max]<arr[l]){max=l;}
    if (r<size && arr[max]<arr[r]){max=r;}
    if (max!=i){
        swap(arr[i],arr[max]);
        heapify(max);
    }
}
void heap_class::heap_heapify(int array[]){
    // we start from the parent of the last leaf all the way to the root 
    for (int i = (size/2)-1,i>=0,i--){
        heapify(i);
    }
}
void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;}

int main(){
//instatiation:
heap_class myheap(7);

}