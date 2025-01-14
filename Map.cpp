#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    // 1. Constructor
    map<int, string> m1;                                         // Default constructor
    map<int, string> m2({{2, "Two"}, {1, "One"}, {3, "Three"}}); // Initialize with elements

    // 2. Insertions
    m1.insert({4, "Four"}); // Using insert(pair)
    m1[5] = "Five";         // Using operator[]
    m1.emplace(6, "Six");   // Using emplace

    // 3. Iterators
    cout << "Elements in m1:\n";
    for (auto it = m1.begin(); it != m1.end(); ++it)
    {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }

    // 4. Access
    cout << "\nAccess element with key 5: " << m1.at(5) << endl;

    // 5. Capacity
    cout << "\nMap m1 size: " << m1.size() << endl;
    cout << "Is m1 empty? " << (m1.empty() ? "Yes" : "No") << endl;

    // 6. Lookup
    cout << "\nLookup functionalities:\n";
    cout << "Find key 5: " << (m1.find(5) != m1.end() ? "Found" : "Not Found") << endl;
    cout << "Count key 7: " << m1.count(7) << endl;

    // lower_bound and upper_bound
    cout << "Lower bound of key 4: Key: " << m1.lower_bound(4)->first << endl;
    if (m1.upper_bound(4) != m1.end())
        cout << "Upper bound of key 4: Key: " << m1.upper_bound(4)->first << endl;

    // 7. Modifiers
    cout << "\nBefore erasing key 4:\n";
    for (const auto &pair : m1)
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;

    m1.erase(4); // Erase by key
    cout << "After erasing key 4:\n";
    for (const auto &pair : m1)
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;

    // Erase using iterator
    auto it = m1.find(5);
    if (it != m1.end())
        m1.erase(it);

    cout << "After erasing key 5:\n";
    for (const auto &pair : m1)
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;

    // Swap maps
    cout << "\nBefore swapping:\n";
    cout << "m1: ";
    for (const auto &pair : m1)
        cout << pair.first << " ";
    cout << "\nm2: ";
    for (const auto &pair : m2)
        cout << pair.first << " ";
    cout << endl;

    m1.swap(m2); // Swap contents of m1 and m2

    cout << "After swapping:\n";
    cout << "m1: ";
    for (const auto &pair : m1)
        cout << pair.first << " ";
    cout << "\nm2: ";
    for (const auto &pair : m2)
        cout << pair.first << " ";
    cout << endl;

    // 8. Observers
    auto comp = m1.key_comp(); // Key comparator
    cout << "\nUsing key_comp to compare keys:\n";
    cout << "Comparing 1 and 3: " << (comp(1, 3) ? "1 < 3" : "1 >= 3") << endl;

    return 0;
}