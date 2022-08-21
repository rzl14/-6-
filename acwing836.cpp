#include <iostream>

using namespace std;

const int N = 100010;

int n, fa[N];

int find(int x) // 返回n的祖宗节点 + 路径压缩
{
    return fa[x] == x? x : fa[x] = find(fa[x]);
}

int main()
{
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) fa[i] = i;
    
    while (m --) {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (*op == 'M') fa[find(a)] = find(b);
        else if(find(a) == find(b)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}