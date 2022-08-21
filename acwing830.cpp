#include <iostream>

using namespace std;

const int N = 100010;

int n, stk[N], tt = -1;

int main()
{
    cin >> n;
    while (n --) {
        int x;
        scanf("%d", &x);
        while (tt >= 0 && stk[tt] >= x) tt --;
        if (tt < 0) cout << -1 << ' ';
        else cout << stk[tt] << ' ';
        stk[++ tt] = x;
    }
}