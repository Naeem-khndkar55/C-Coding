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
// bulid balanced BST
Node *buildBalancedBST(vector<int> arr, int st, int ed)
{
    if (st > ed)
    {
        return NULL;
    }
    int mid = st + (ed - st) / 2;
    Node *root = new Node(arr[mid]);
    root->left = buildBalancedBST(arr, st, mid - 1);
    root->right = buildBalancedBST(arr, mid + 1, ed);
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
// for marge two BST
void inorderBST(Node *root, vector<int> &arr)
{

    if (root == NULL)
    {
        return;
    }
    inorderBST(root->left, arr);
    arr.push_back(root->data);
    inorderBST(root->right, arr);
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
// marge 2 bst
Node *MargeTwoBST(Node *root1, Node *root2)
{
    vector<int> arr1;
    vector<int> arr2;
    inorderBST(root1, arr1);
    inorderBST(root2, arr2);
    vector<int> finl;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            finl.push_back(arr1[i]);
            i++;
        }
        else
        {
            finl.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size())
    {
        finl.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size())
    {
        finl.push_back(arr2[j]);
        j++;
    }
    Node *root = buildBST(finl);                              // normal bst
    Node *root3 = buildBalancedBST(finl, 0, finl.size() - 1); // balanced bst;
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