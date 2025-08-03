#include <iostream>
#include <string>
#include <utility> // for pair

using namespace std;

template <typename elem>
class bst {
public:
    struct node {
        pair<int, elem> p;  // pair to store key and data
        node* left;
        node* right;
        
        // Constructor for node
        node(int k, elem data)
            : p(k, data), left(nullptr), right(nullptr) {}
    };

    node* root;

    bst(int key, elem data);
    ~bst();

    node* search(node* root, int k);
    node* insert(node* root, pair<int, elem> data);
    node* deleting(int k, node* root);
    void inorder(node* root);
    void deleteTree(node* root);
};

// Constructor for bst
template <typename elem>
bst<elem>::bst(int key, elem data) : root(new node(key, data)) {}

// Destructor for bst
template <typename elem>
bst<elem>::~bst() {
    deleteTree(root);
}

// Helper function to delete tree nodes recursively
template <typename elem>
void bst<elem>::deleteTree(node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Search function
template <typename elem>
typename bst<elem>::node* bst<elem>::search(node* root, int k) {
    if (root == nullptr || root->p.first == k) {
        return root;
    }
    if (k < root->p.first) {
        return search(root->left, k);
    }
    return search(root->right, k);
}

// Insert function
template <typename elem>
typename bst<elem>::node* bst<elem>::insert(node* root, pair<int, elem> data) {
    if (root == nullptr) {
        return new node(data.first, data.second);
    }

    if (data.first < root->p.first) {
        root->left = insert(root->left, data);
    }
    else if (data.first > root->p.first) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Deletion function
template <typename elem>
typename bst<elem>::node* bst<elem>::deleting(int k, node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    if (k < root->p.first) {
        root->left = deleting(k, root->left);
    }
    else if (k > root->p.first) {
        root->right = deleting(k, root->right);
    }
    else {
        // Case 1: No children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: One child
        if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        node* temp = root->right;
        while (temp && temp->left != nullptr) {
            temp = temp->left;
        }

        root->p = temp->p;
        root->right = deleting(temp->p.first, root->right);
    }

    return root;
}

// Inorder traversal function
template <typename elem>
void bst<elem>::inorder(node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << "(" << root->p.first << ", " << root->p.second << ") ";
    inorder(root->right);
}

// Main function for testing
/*int main() {
    // Create a BST with an initial key-value pair
    bst<int> tree(10, 100);  // Root node with key 10 and data 100

    // Insert some elements
    tree.root = tree.insert(tree.root, {5, 50});
    tree.root = tree.insert(tree.root, {20, 200});
    tree.root = tree.insert(tree.root, {3, 30});
    tree.root = tree.insert(tree.root, {7, 70});

    cout << "Inorder traversal after initial insertions:\n";
    tree.inorder(tree.root);  // Should print the elements in order

    // Delete a node
    tree.root = tree.deleting(7, tree.root);
    cout << "\nInorder traversal after deleting node with key 7:\n";
    tree.inorder(tree.root);

    // Search for a key
    node* result = tree.search(tree.root, 20);
    if (result != nullptr) {
        cout << "\nNode with key 20 found, data: " << result->p.second << endl;
    }
    else {
        cout << "\nNode with key 20 not found." << endl;
    }

    return 0;
}*/
