#include <iostream>
#include <string>
using namespace std; 

struct ptrnode {
    string element;
    ptrnode* next;
};

class linked_list_class {
    ptrnode* head;

public:
    void init(linked_list_class& l) {
        l.head = NULL;
    }

    bool isempty(linked_list_class& l) {
        if (l.head == NULL) {
            cout << "list is empty" << endl;
            return true;
        } else {
            return false;
        }
    }

    int sizeof_linkedlist(linked_list_class& l) {
        ptrnode* temp = l.head;
        int count = 0;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
        return count;
    }

    void insert(linked_list_class& l, string value, int pos) {
        ptrnode* v = new ptrnode;
        v->element = value;
        if (l.head == NULL) {
            if (pos != 0) {
                cout << "no" << endl;
            } else {
                l.head = v;
                l.head->next = NULL;
            }
        } else {
            if (pos == 0) { // Inserting in the front
                v->next = l.head;
                l.head = v;
            } else {
                ptrnode* temp = l.head;
                int j = 0;
                while (temp != NULL && j < pos - 1) {
                    temp = temp->next;
                    j++;
                }
                if (temp != NULL) {
                    v->next = temp->next;
                    temp->next = v;
                } else {
                    cout << "invalid" << endl;
                }
            }
        }
    }

    void deleting(linked_list_class& l, int pos) {
        if (l.head == NULL) {
            cout << "ur list is empty" << endl;
        } else {
            ptrnode* v;
            ptrnode* t = l.head;
            if (pos == 0) {
                v = l.head;
                l.head = l.head->next;
                delete v;
            } else {
                unsigned j = 0;
                while (t != NULL && j < pos - 1) {
                    t = t->next;
                    j++;
                }
                if (t == NULL || t->next == NULL) {
                    cout << "badd position " << endl;
                } else {
                    v = t->next;
                    t->next = v->next;
                    delete v;
                }
            }
        }
    }

    int search(linked_list_class& l, string value) {
        if (l.head == NULL) {
            return -1;
            cout << "ur list is empty" << endl;
        } else {
            ptrnode* temp = l.head;
            int i = 0;
            while (temp != NULL) {
                if (temp->element == value) {
                    return i;
                }
                temp = temp->next;
                i++;
            }
            return -1;
        }
    }

    string traverse(linked_list_class& l) {
        if (l.head == NULL) {
            return "ur list is empty";
        }
        ptrnode* temp = l.head;
        string result = "";
        while (temp != NULL) {
            result += temp->element + " ";
            temp = temp->next;
        }
        return result;
    }

    void backward(ptrnode* cur) {
        if (cur != NULL) {
            backward(cur->next);
            cout << cur->element << " ";
        }
    }

    string traverse_backward(linked_list_class& l) {
        if (l.head == NULL) {
            cout << "your list is empty " << endl;
        } else {
            cout << "[";
            backward(l.head);
            cout << "]" << endl;
        }
        return "";
    }
};

int main() {
    linked_list_class obj;
    linked_list_class mylist;
    obj.init(mylist);
    
    int choice, pos;
    string value;
    
    while (true) {
        cout << "Menu:" << endl;
        cout << "1.Insert" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Search" << endl;
        cout << "4.Traverse forward" << endl;
        cout << "5.Traverse backward" << endl;
        cout << "6.Check if Empty" << endl;
        cout << "7.Exit" << endl;
        cout << "Enter your choice: ";
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
                cout << "enter position to be deleted : ";
                cin >> pos;
                obj.deleting(mylist, pos);
                break;

            case 3:
                cout << "enter the search value : ";
                cin >> value;
                pos = obj.search(mylist, value);
                if (pos != -1) {
                    cout << pos << endl;
                } else {
                    cout << "it doesnt exist " << endl;
                }
                break;

            case 4:
                cout << obj.traverse(mylist) << endl;
                break;

            case 5:
                obj.traverse_backward(mylist);
                break;

            case 6:
                if (obj.isempty(mylist)) {
                    cout << "The list is empty." << endl;
                } 

            case 7:
                return 0;
        }
    }

    return 0;
}
