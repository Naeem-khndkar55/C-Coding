#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Node
{
    // boiler plate
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// insertion of the node
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}
// buliding BST function
Node *buildBST(vector<int> arr)
{
    Node *root = NULL;
    for (auto val : arr)
    {
        root = insert(root, arr[val]);
    }
    return root;
}

// search a key in BST
bool searchKey(Node *root, int key) // bigO(height)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    else if (root->data > key)
    {
        return searchKey(root->left, key);
    }
    else
    {
        return searchKey(root->right, key);
    }
}
// output in sorted array
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// incorder successor
Node *inorderSuccessor(Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
// delete a node
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data < key)
    {
        deleteNode(root->right, key);
    }
    else if (root->data > key)
    {
        deleteNode(root->left, key);
    }
    else
    {

        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *IS = inorderSuccessor(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right, IS->data);
        }
    }
    return root;
}
int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node *root = buildBST(arr); // build function
    inorder(root);
    int key = 6;
    cout << endl;
    cout << searchKey(root, key) << endl;
    // delete a node
    deleteNode(root, key);
    Node *root = buildBST(arr); // build function
    inorder(root);
    return 0;
}