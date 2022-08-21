#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int h[N], e[M], ne[M], d[M], idx;
int dist[N], backup[N];

void add(int a, int b, int w)
{
    e[idx] = b, d[idx] = w, ne[idx] = h[a], h[a] = idx ++;
}

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < k; i ++)
    {
        memcpy(backup, dist, sizeof dist);
        for (int j = 1; j <= n; j ++)
            for (int t = h[j]; ~t; t = ne[t])
                dist[e[t]] = min(dist[e[t]], backup[j] + d[t]);
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        add(a, b, w);
    }

    bellman_ford();

    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d\n", dist[n]);

    return 0;
}