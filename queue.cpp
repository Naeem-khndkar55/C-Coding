#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }

    void push(int data)
    { // Add parameter to push
        Node *newNode = new Node(data);
        if (empty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL)
            tail = NULL; // Important to reset tail when queue becomes empty
    }

    int front()
    { // Return int instead of void
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head->data;
    }

    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while (!q.empty())
    {
        cout << "Front: " << q.front() << endl;
        q.pop();
    }
    cout << "Front: " << q.front() << endl;
    return 0;
}

// using stl;

// queue<int>q;
// Deque->>>Double Ended Queue (can push /pop from both side)
// deque<int> (push_front ,push_back,pop_front pop_back)