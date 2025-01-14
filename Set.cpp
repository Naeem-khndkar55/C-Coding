#include <bits/stdc++.h>
using namespace std;

int main()
{

    // 1. Using ordered set

    set<int> s;

    // Inserting elements
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(15);
    s.insert(10); // Duplicate (ignored)

    cout << "Elements in set (ordered):\n";
    for (int elem : s)
        cout << elem << " "; // Output: 5 10 15 20
    cout << endl;

    // Access and Lookup
    cout << "\nFinding elements in set:\n";
    cout << "Does 10 exist? " << (s.find(10) != s.end() ? "Yes" : "No") << endl; // Yes
    cout << "Does 25 exist? " << (s.count(25) ? "Yes" : "No") << endl;           // No

    // Lower and Upper Bounds
    cout << "Lower bound of 10: " << *s.lower_bound(10) << endl; // 10
    if (s.upper_bound(10) != s.end())
        cout << "Upper bound of 10: " << *s.upper_bound(10) << endl; // 15

    // Erasing elements
    s.erase(10); // Remove 10
    cout << "\nSet after erasing 10:\n";
    for (int elem : s)
        cout << elem << " "; // Output: 5 15 20
    cout << endl;

    // Iterators
    cout << "\nUsing reverse iterator:\n";
    for (auto rit = s.rbegin(); rit != s.rend(); ++rit)
        cout << *rit << " "; // Output: 20 15 5
    cout << endl;

    // Observers
    auto comp = s.key_comp();
    cout << "\nUsing key_comp to compare keys:\n";
    cout << "Is 5 < 15? " << (comp(5, 15) ? "Yes" : "No") << endl;

    // 2. Using std::unordered_set

    unordered_set<int> us;

    // Inserting elements
    us.insert(10);
    us.insert(5);
    us.insert(20);
    us.insert(15);
    us.insert(10); // Duplicate (ignored)

    cout << "\nElements in unordered_set:\n";
    for (int elem : us)
        cout << elem << " "; // Order not guaranteed
    cout << endl;

    // Lookup
    cout << "\nFinding elements in unordered_set:\n";
    cout << "Does 20 exist? " << (us.find(20) != us.end() ? "Yes" : "No") << endl; // Yes

    // Erasing elements
    us.erase(5); // Remove 5
    cout << "\nUnordered_set after erasing 5:\n";
    for (int elem : us)
        cout << elem << " "; // Order not guaranteed
    cout << endl;

    // Bucket Information
    cout << "\nBucket information for unordered_set:\n";
    cout << "Number of buckets: " << us.bucket_count() << endl;
    for (size_t i = 0; i < us.bucket_count(); ++i)
    {
        cout << "Bucket " << i << ": ";
        for (auto it = us.begin(i); it != us.end(i); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}
