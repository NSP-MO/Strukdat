#include <bits/stdc++.h>
using namespace std;

vector<int> getValues()
{
    vector<int> v;
    for (int i = 0; i < 10; i++) v.push_back(i + 1);
    return v;
}

int main()
{
    vector<int> get;
    get = getValues();

    vector<int>::iterator it;
    for (it = get.begin(); it != get.end(); ++it) 
        cout << *it << " ";

return 0;
}
