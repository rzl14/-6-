#include <iostream>

using namespace std;

const int N = 100010;

int fa[N], cnt[N];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) fa[i] = i, cnt[i] = 1;
    
    while (m --) {
        string op;
        int a, b;
        cin >> op;

        if (op == "C"){
            scanf("%d%d", &a, &b);
            a = find(a), b = find(b);
            if (a != b) {
                cnt[a] += cnt[b];
                fa[b] = a;
            }
        }
        else if (op == "Q1") {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) printf("Yes\n");
            else printf("No\n");
        }
        else 
        {
            scanf("%d", &a);
            printf("%d\n", cnt[find(a)]);
        }
    }
    
    return 0;
}