#include<iostream>
#include<string>
# include<list>

using namespace std ;
template<typename T>;
// do calls for each methode of colusion i guess is better 

//the class:
class hash_class {
    //array ,size
public:
        list<pair<string,T>* arr1
        pair<string,T>* arr2;
        pair<string,T>* arr3;
        pair<string,T>* arr4;
        bool* track2,
        bool* track3,
        bool* track4,

        int capacity;
        int size;
        // the methodes :
        hash_class(int cap);
        ~hash_class();
        int hash(string k);
        T search(string k);
        void chaining(string k. T value);

}
hash_class:: hash_class(int cap){
    capacity=cap ;
    size=0;
    //allocation :
    arr1=new list<string,T>[capacity];

    arr2=new pair<string,T>[capacity];
    track2= new int[capacity]{false};

    arr3=new pair<string,T>[capacity];
    track3= new int[capacity]{false};

    arr4=new pair<string,T>[capacity];
    track4= new int[capacity]{false};
}
hash_class::~hash_class(){
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
}
int hash_class:: hash(string k){
    int string_value=0;
    int the_hash;
    for(char c:k){
       string_value=string_value+c;
    }
    the_hash=string_value % capacity;
    return the_hash;
}
int hash_class:: second_hash(string k){
    int string_value=0;
    int the_hash;
    for(char c:k){
       string_value=string_value+c;
    }
    the_hash=(string_value*0.5) % capacity;
    return the_hash;
}


// search for the array based :
T hash_class:: arr_search(string k){
    // find the hash 
    int the_hash=hash(k);
    if (arr2[the_hash].first==k){return arr2[the_hash].second;}
    else {throw " not found" ;}
    
    if (arr3[the_hash].first==k){return arr3[the_hash].second;}
    else {throw " not found" ;}

    if (arr4[the_hash].first==k){return arr4[the_hash].second;}
    else {throw " not found" ;}}
// search for the linked list array:
T hash_class:: chain_search(string k){
  // we need to traverse the list of the hash
  int the_hash=hash(k);
  // traversing 
  node* temp=arr1[the_hash];
  bool flag=true;
  while(temp->next!=NULL){
    if (templ->elem.first==k){
        flag=true;
        break;
    }
    temp=temp->next;
  }
  if(flag==true){return temp->elem.second}
  else{ trow "not found"}
}

//  insertion for chaining methode 
bool chain_insert(string k,T value){
    int the_hash=hash();
    chain_search(k)
    arr1[the_hash].insert(k,value);
    retun true;
}
// insertion in linear probing :
bool linear_insert(string k,T value){
    int the_hash=hash();
    if(track2[the_hash]==false){
        //we insert:
        arr2[the_hash].first=k;
        arr2[the_hash].second=value;
        track2[the_hash]=true;
        return true;
    }
    else{
         // insert in the next empty :
         // traverse the array from the_hash till its empty :
         for(int i=the_hack+1;i<capacity;i++){
            if(track2[i]==false){
                arr2[i].first=k;
                arr2[i].second=value;
                track2[i]=true;
                break;
                return true;}
            if(i==capacity-1 && track2[i]==true){
                cout << "we cant insert";
                return false;
            }
         }
    }
}
// insertion in quadratic hashing :
bool quadratic_insert(string k,T value){
    // if we can we insert in the hash 
    int the_hash=hash(k);
    if(track3[the_hash]==false){
        //we insert:
        arr3[the_hash].first=k;
        arr3[the_hash].second=value;
        track3[the_hash]=true;
        return true;
    }
    else{
        // in case of colussion we calculate new index 
        for(int i=0;i<capacity;i++){
            int the_hash2=(hash(k)+i^2)%  size;
            //  we check for the new hash :
            if(track3[the_hash2]==false){
                //we insert:
                arr3[the_hash2].first=k;
                arr3[the_hash2].second=value;
                track3[the_hash2]=true;
                return true;
                break;}
            if(the_hash2>capacity){
                cout<<" we cant insert ";
                return false 
            }
            }

    }
}
// insertino in double hashing :
bool dh_insert(string k ,T value){
    // if we can insert we insert normalyy 
// if we can we insert in the hash 
    int the_hash=hash(k);
    if(track4[the_hash]==false){
        //we insert:
        arr4[the_hash].first=k;
        arr4[the_hash].second=value;
        track4[the_hash]=true;
        return true;
    }
    else{
        // in case of colussion we calculate new index 
        for(int i=0;i<capacity;i++){
            int the_hash2=(hash(k)+(i^2)*second_hash(k))%  size;
            //  we check for the new hash :
            if(track4[the_hash2]==false){
                //we insert:
                arr4[the_hash2].first=k;
                arr4[the_hash2].second=value;
                track4[the_hash2]=true;
                return true;
                break;}
            if(the_hash2>capacity){
                cout<<" we cant insert ";
                return false 
            }
            }

    }
    }

// the remove methodes :
// 1 remove key from the chaining array :
bool chain_remove( string k){
    // delete the node of that key :
    int the_hash=hash(k);
    // traverse the list of the index and delete the node if it exist 
    node* head= arr1[the_hash];
    node* temp=head;
    // traversing till we find it :
    while(temp->next!= NULL){
        if (temp->elem.first==k){
            arr1[the_hash].delete(k);
            return true;
            break;   }
            return false;
}}
// now deleting in the arrays ,we must do the shiftting :
bool arr_delete(string k ){
    // we have to shift from the one after the thhe_hash to the satart and decrease the size 
    int the_hash=hash(k);
    // we loop and do the shifftting :

    for (int i=the_hash;i<capacity;i++){
         arr2[i]=arr2[i+1]; }
    
    for (int i=the_hash;i<capacity;i++){
        arr3[i]=arr3[i+1]; }
    
    for (int i=the_hash;i<capacity;i++){
        arr4[i]=arr4[i+1]; }
    size--;
}




