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
// building Binary Tree;
static int idx = -1;
Node *buildTree(vector<ll> preOrder)
{
    idx++;
    if (preOrder[idx] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->left = buildTree(preOrder);
    return root;
}
// pre order traversal= root-> left sub tree-> right sub tree
void preOderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    preOderTraversal(root->left);
    preOderTraversal(root->right);
}
// in order traversal= left sub tree->root->right sub tree
void inOderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOderTraversal(root->left);
    cout << root->data << endl;
    inOderTraversal(root->right);
}
// post order travesal=left sub tree ->right sub tree -> root
void postOderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOderTraversal(root->left);
    postOderTraversal(root->right);
    cout << root->data << endl;
}
//  3 traversal algorithm use reccurtion to traverse a binary tree
// iterative approach level order travesal
void levelOder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();
        // showing the tree level by level
        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }
        cout << curr->data << " ";
        if (curr->left != NULL)
        {
            q.push(root->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
    cout << endl;
}
// top view of a binart tree
void topView(Node *root)
{
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    map<int, int> mp;
    while (q.size() > 0)
    {
        Node *curr = q.front().first;
        int currHd = q.front().second;
        q.pop();
        if (mp.find(currHd) == mp.end())
        {
            mp[currHd] = curr->data;
        }
        if (curr->left != NULL)
        {
            q.push({root->left, currHd - 1});
        }
        if (curr->right != NULL)
        {
            q.push({curr->right, currHd + 1});
        }
    }
    for (auto i : mp)
    {
        cout << i.second << " ";
    }
    cout << endl;
}
// kth of the binary tree
void KthLevel(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    KthLevel(root->left, k - 1);
    KthLevel(root->right, k - 1);
}
//  height of binary tree
int heightOfBinaryTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHt = heightOfBinaryTree(root->left);
    int rightHt = heightOfBinaryTree(root->right);
    return max(leftHt, rightHt) + 1;
}
// count the node of the tree
int nodeCount(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftNode = nodeCount(root->left);
    int rightNode = nodeCount(root->right);
    return leftNode + rightNode + 1;
}
// sum of the nodes
int sumOfNodes(Node *root)
{
    if (root = NULL)
    {
        return 0;
    }
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return leftSum + rightSum + root->data;
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> val(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    // build tree
    Node *root = buildTree(val);
    // traversial of the tree
    preOderTraversal(root);
    inOderTraversal(root);
    postOderTraversal(root);
    levelOder(root);
    topView(root);
    int k = 3; // number of level
    KthLevel(root, k);
    // height ,count node,sum of all nodes
    int hight = heightOfBinaryTree(root);
    cout << hight << endl;
    int nodeCnt = nodeCount(root);
    cout << nodeCnt << endl;
    int sumOfNodeValue = sumOfNodes(root);
    cout << sumOfNodeValue << endl;
    cout << root->data << endl;
}