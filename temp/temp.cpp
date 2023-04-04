#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

ostream& operator<<(ostream& out, pair<int, int> mp)
{
    out << mp.first << " - " << mp.second;
    return out;
}
bool operator ==(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first == p2.first && p1.second == p2.second || p1.first == p2.second && p1.second == p2.first;
}

int dividers_sum(int num)
{
    int sum = 0;
    if (num % 2 != 0)
    {
        for (int i = 1; i < num; i += 2)
        {
            if (num % i == 0)
                sum += i;
        }
    }
    else
    {
        for (int i = 1; i < num; i++)
        {
            if (num % i == 0)
                sum += i;
        }
    }
    return sum;
}

bool isthere(pair<int, int> pr, map<int, int> mp)
{
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (*i == pr)
            return false;
    }
}

int main()
{
    srand(time(NULL));

    cout << "Started" << endl;

    map<int, int> friends;

    int temp;
    for (int i = 4; i <= 16384; i++)
    {
        temp = dividers_sum(i);
        if (i == dividers_sum(temp) && i != temp && isthere(pair<int, int>(i, temp), friends))
            friends.emplace(i, temp);
    }

    for (auto i = friends.begin(); i != friends.end(); i++)
    {
        cout << *i << endl;
    }

    return 0;
}