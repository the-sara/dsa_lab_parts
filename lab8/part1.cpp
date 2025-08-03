#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include "heap_ds.cpp"
#include "bst_ds.cpp"

using namespace std;

template <typename elem>
void preOrder(typename bst<elem>::Node* root, bst<elem>& huffmanTree, string curr) {
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr) {
        huffmanTree.root = huffmanTree.insert(huffmanTree.root, {root->data, curr});
        return;
    }

    preOrder(root->left, huffmanTree, curr + '0');
    preOrder(root->right, huffmanTree, curr + '1');
}

vector<string> huffmanCodes(const string& s, const vector<int>& freq) {
    int n = s.length();
    
    vector<pair<int, char>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = {freq[i], s[i]};
    }

    heap_class<char> minHeap(arr, n, 256);

    bst<char> huffmanTree(0, ' ');

    while (minHeap.size > 1) {
        pair<int, char> left = minHeap.arr[0];
        minHeap.deletting();
        pair<int, char> right = minHeap.arr[0];
        minHeap.deletting();

        int sum = left.first + right.first;
        huffmanTree.root = huffmanTree.insert(huffmanTree.root, {sum, ' '});

        minHeap.insert(sum, ' ');
    }

    cout << "Huffman Tree Root Key: " << minHeap.arr[0].first << endl;

    preOrder(huffmanTree.root, huffmanTree, "");

    vector<string> codes;
    huffmanTree.inorder(huffmanTree.root);
    return codes;
}

int main() {
    string s = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    vector<string> ans = huffmanCodes(s, freq);

    cout << "Huffman Codes: ";
    for (const auto& code : ans) {
        cout << code << " ";
    }

    return 0;
}
