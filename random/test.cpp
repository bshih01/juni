#include <unordered_map>
#include <typeinfo>
using namespace std;


void output_Node(TreeNode *root) {
    string s;
    outputNodeHelper(root, s);
}
void outputNodeHelper(TreeNode *root, string code) {
    if (root == nullptr) {
        return;
    } if ((root->left == nullptr) and (root->right == nullptr)) {
        cout << root->data << ": " << code << endl;
    } else {
        outputNodeHelper(root->left, code + "0");
        outputNodeHelper(root->right, code + "1");
    }
}

LinkedList *BST::reverseSort() {
    LinkedList *list;
    reverseSortHelper(list, root)
    return list;
}
void BST::reverseSortHelper(LinkedList *list, Node *curr) {
    // base cases
    if (curr == nullptr) {
        return;
    } else {
        reverseSortHelper(list, curr->right);
        list.push_back(curr->data);
        reverseSortHelper(list, curr->left);
    }
}

unordered_map<int, int> map;
auto i = map;
