#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v;
    vector<char> vchar = {'a', 'c', 'f', 'd', 'z'};

    for (int i = 0; i < vchar.size(); i++) {
        v.push_back(vchar[i]);
    }


    // Accessing and printing values using indexes
      cout << vchar[3] << endl;
      cout << vchar.at(2) << endl;
      cout << vchar.front() << endl;
      cout << vchar.back() << endl;
    return 0;
}