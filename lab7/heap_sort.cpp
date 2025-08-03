#include<iostream>
#include<string>
#include "heap_ds.cpp"
using namespace std;

// Use heap to sort array
void sort(int array[]){
    int out_array[7];
    heap_class h(array, 7, 10); // instantiate heap with buffer
    int* heap1 = h.heap_heapify();  

    heap_class h2(heap1, 7, 10);  

    for(int i = 0; i < 7; i++){
        out_array[i] = h2.peak();  
        //heapifying :
        heap1[0]=heap1[h2.size-1];
        h2.size--;
        // than we heapify
        h2.heapify(0);
    }

    for(int i = 0; i < 7; i++){
        cout << out_array[i] << " ";
    }
    cout << endl;
}
void minh(heap_class& h) {
    std::swap(h.arr[0],h.arr[h.size-1]);
    for (int i = (h.size/2)-1;i>=0;i--){
    int l=h.left(i);
    int r=h.right(i);
    int min=i;
    if (l<h.size && h.arr[min]>h.arr[l]){min=l;}
    if (r<h.size && h.arr[min]>h.arr[r]){min=r;}
    if (min!=i){
        std::swap(h.arr[i],h.arr[min]);
    }}
    h.print();
}


int main(){
    int array4[] = {12, 3, 5, 6, 13, 44, 6};
    int array7[] = {100, 50, 90, 40, 45, 80, 85};
    // creating the heap objest :
    heap_class heapp(array7,7,10);
    minh(heapp);
    sort(array4);
    return 0;
}
