#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node
{
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

// build BST function
Node *buildBST(vector<int> arr)
{
    Node *root = NULL;
    for (auto val : arr) // fixed: arr[val] → val
    {
        root = insert(root, val);
    }
    return root;
}

// build balanced BST
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
bool searchKey(Node *root, int key)
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

// store inorder traversal into vector
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

// inorder successor
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
        root->right = deleteNode(root->right, key); // fixed
    }
    else if (root->data > key)
    {
        root->left = deleteNode(root->left, key); // fixed
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

// merge 2 BSTs
Node *MargeTwoBST(Node *root1, Node *root2)
{
    vector<int> arr1, arr2;
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

    cout << "Merged Array: ";
    for (int x : finl)
        cout << x << " ";
    cout << "\n";

    Node *rootNormal = buildBST(finl);                               // normal BST
    Node *rootBalanced = buildBalancedBST(finl, 0, finl.size() - 1); // balanced BST

    cout << "Inorder of Merged Normal BST: ";
    inorder(rootNormal);
    cout << "\n";

    cout << "Inorder of Merged Balanced BST: ";
    inorder(rootBalanced);
    cout << "\n";

    return rootBalanced; // returning balanced as final root (you can change if needed)
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    vector<int> arr2 = {2, 3, 8, 9};

    Node *root1 = buildBST(arr);  // build function
    Node *root2 = buildBST(arr2); // build function

    cout << "BST1 inorder: ";
    inorder(root1);
    cout << "\n";

    cout << "BST2 inorder: ";
    inorder(root2);
    cout << "\n";

    int key = 6;
    cout << "Search for " << key << ": " << searchKey(root1, key) << "\n";

    // delete a node from first BST
    root1 = deleteNode(root1, key);
    cout << "BST1 inorder after deletion: ";
    inorder(root1);
    cout << "\n";

    // merge 2 BSTs
    Node *merged = MargeTwoBST(root1, root2);

    return 0;
}
