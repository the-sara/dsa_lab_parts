#include <iostream>
#include <string>
using namespace std;

#define max 6

struct arraylist {
    int size;
    string arrelements[max];
};

class array_list_class {
    arraylist arrlist;

public:
    void init(arraylist &l) {
        l.size = 0;
    }

    bool isempty(arraylist l) {
        return l.size == 0;
    }

    int sizeof_arraylist(arraylist l) {
        return l.size;
    }

    void insert(arraylist &l, string value, int pos) {
        if (l.size == max) {
            cout << "full" << endl;
        } else if (pos > l.size) {
            cout << "invalid" << endl;
        } else {
            for (int i = l.size; i > pos; i--) {
                l.arrelements[i] = l.arrelements[i - 1];
            }
            l.arrelements[pos] = value;
            l.size++;
        }
    }

    void deleting(arraylist &l, int pos) {
        if (l.size == 0) {
            cout << "It is empty" << endl;
        } else if (pos >= l.size) {
            cout << "You can't delete from this position" << endl;
        } else {
            for (int i = pos; i < l.size - 1; i++) {
                l.arrelements[i] = l.arrelements[i + 1];
            }
            l.size--;
        }
    }

    int search(arraylist &l, string value) {
        if (l.size == 0) {
            cout << "It is empty" << endl;
            return -1;
        } else {
            for (int i = 0; i < l.size; i++) {
                if (l.arrelements[i] == value) {
                    return i;
                }
            }
            return -1; 
        }
    }

    void traverse(arraylist &l) {
        if (l.size == 0) {
            cout << "It is empty" << endl;
        } else {
            for (int i = 0; i < l.size; i++) {
                cout << l.arrelements[i] << " ";
            }
        }
    }

    void traverse_backward(const arraylist &l)  {
        if (l.size == 0) {
            cout << "It is empty" << endl;
        } else {
            for (int i = l.size - 1; i >= 0; i--) {
                cout << l.arrelements[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    array_list_class obj;
    arraylist mylist;
    obj.init(mylist);
    
    int choice, pos;
    string value;
    
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Traverse (Forward)" << endl;
        cout << "5. Traverse (Backward)" << endl;
        cout << "6. Check if Empty" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                obj.insert(mylist, value, pos);
                break;
                
            case 2:
                cout << "enter the position to be deleted : ";
                cin >> pos;
                obj.deleting(mylist, pos);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                pos = obj.search(mylist, value);
                if (pos != -1) {
                    cout << "Found at index " << pos << endl;
                } else {
                    cout << "Not found" << endl;
                }
                break;

            case 4:
                obj.traverse(mylist);
                break;

            case 5:
                obj.traverse_backward(mylist);
                break;

            case 6:
                if (obj.isempty(mylist)) {
                    cout << "The array is empty." << endl;
                } else {
                    cout << "The array is not empty." << endl;
                }
                break;

            case 7:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice, please try again!" << endl;
                break;
        }
    }

    return 0;
}
