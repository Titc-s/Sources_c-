#include <bits/stdc++.h>
using namespace std;
struct edge {
    int l, r, w;
}e[5005];
bool cmp(edge A, edge B) {
    return A.r < B.r;
}
int n, m, ans = 0, vis[30005];
int main() {while(scanf("%d%d",&n, &m)!=EOF)
{
	for (int i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].l, &e[i].r, &e[i].w);
    sort(e, e + m, cmp);
    for (int i = 0; i < m; i++) {
        int s = 0;
        for (int j = e[i].l; j <= e[i].r && s < e[i].w; j++)
            if (vis[j])
                s++;
        for (int j = e[i].r; j >= e[i].l && s < e[i].w; j--) {
            if (!vis[j]) {
                s++;
                ans++;
                vis[j] = 1;
            }
        }
    }
    printf("%d\n", ans);
}
    
    
    return 0;
}
