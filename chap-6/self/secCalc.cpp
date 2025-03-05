#include <vector>
#include <iostream>

using namespace std;

int search(vector<int> &a, int n, int init, int end) {
    if (init > end) return end + 1;
    int mid = init + (end - init) / 2;
    if (a[mid] == n) return mid;
    if (a[mid] < n) return search(a, n, mid + 1, end);
    return search(a, n, init, mid - 1);
}

int main() {
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(3);

    int sigma = 2;
    int fn = 3;
    int n = 3;

    while (n <= 2000000000)
    {
        n += sigma;
        a.push_back(n);
        if (a[sigma] == fn) sigma++;
        fn++;
    }

    int in;
    while (cin >> in && in != 0)
    {
        cout << search(a, in, 1, a.size() - 1) << endl;
    }
}