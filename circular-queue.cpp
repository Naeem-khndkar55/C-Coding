#include <bits/stdc++.h>
using namespace std;

class circularQueue
{
    int *arr;
    int currSize, cap;
    int f, r;

public:
    circularQueue(int size)
    {
        cap = size;
        arr = new int[cap];
        f = 0;
        r = -1;
        currSize = 0;
    }

    ~circularQueue()
    {
        delete[] arr;
    }

    void push(int data)
    {
        if (currSize == cap)
        {
            cout << "Queue is full\n";
            return;
        }
        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }

    void pop()
    {
        if (empty())
        {
            cout << "Circular queue is empty\n";
            return;
        }
        f = (f + 1) % cap;
        currSize--;
    }

    int front()
    {
        if (empty())
        {
            cout << "Circular queue is empty\n";
            return -1;
        }
        return arr[f];
    }

    bool empty()
    {
        return currSize == 0;
    }

    int size()
    {
        return currSize;
    }

    void display()
    {
        if (empty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < currSize; i++)
        {
            cout << arr[(f + i) % cap] << " ";
        }
        cout << endl;
    }
};

int main()
{
    circularQueue cq(5); // must provide size

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.display(); // Output: Queue: 1 2 3

    cout << "Front: " << cq.front() << endl; // Output: Front: 1

    cq.pop();
    cq.display(); // Output: Queue: 2 3

    cq.push(4);
    cq.push(5);
    cq.push(6);
    cq.display(); // Output: Queue: 2 3 4 5 6

    cq.push(7); // Queue is full

    return 0;
}
