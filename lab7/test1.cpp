
#include<iostream>
#include<string>
using namespace std;

//implemeting the data structure :
//max heap:
class heap_class{
private:
        //array ,size,capacity;
        int size;
        int capacity;//for the allocation
        int* arr; 
public:
       heap_class(int array[],int mysize,int cap);
       ~heap_class();
       int peak();
       void insert(int k );
       int left(int i){return (2*i+1);}
       int right(int i){return (2*i+2);}
       int parent(int i){return (i-1)/2;}
       void print() ;
       void heapify(int i);
       void heap_heapify();
       void deletting();//delete the root 

};
//implemeting the methodes bodies :
//the constructor and destructor :
heap_class::heap_class(int array[],int mysize,int cap){
/// allocate array with this capacity :
    //arr=new int[cap];//alocating the memeo 
    capacity=cap;
    size = mysize;
    arr=array;
}
heap_class::~heap_class(){
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
        arr[size]=k;
        int i=size;
        size++;
        //checking and swapping :
        while(i>0 && (arr[i]>arr[parent(i)])){
            std::swap(arr[i],arr[parent(i)]);
            i=parent(i); }}
        }
void heap_class::print() {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
void heap_class::heapify(int i){//swap parent with the better fit childe 
    int l=left(i);
    int r=right(i);
    int max=i;
    if (l<size && arr[max]<arr[l]){max=l;}
    if (r<size && arr[max]<arr[r]){max=r;}
    if (max!=i){
        std::swap(arr[i],arr[max]);
        heapify(max);
    }}
void heap_class::heap_heapify(){
     // we start from the parent of the last leaf all the way to the root 
    for (int i = (size/2)-1;i>=0;i--){
        heapify(i);
        }
    }
void heap_class::deletting(){
    //delete the root
    arr[0]=arr[size-1];
    size--;
    // than we heapify
    heapify(0);
    }

int main(){
    //instatiation:,
    int array1[]={90, 85, 80, 60, 40, 30, 10};
    int array2[]={42,55,1,2,8,54,34,22};
    heap_class myheap1(array1,7,10);
    heap_class myheap2(array2,8,10);
    myheap1.insert(80);
    myheap1.print();
    myheap2.heap_heapify();
    myheap2.print();
    myheap1.deletting();
    myheap1.print();
    }
    