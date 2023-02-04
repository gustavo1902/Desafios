#include <bits/stdc++.h>
using namespace std;
int T, m, n, a, b, x, y, ans;
char s[105][105];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool used[105][105];
bool bfs(int x, int y)
{
queue<pair<int, int> > q;
q.push(make_pair(x, y));
memset(used, false, sizeof used);
used[x][y] = true;
int cnt = 0;
while (!q.empty())
{
int x = q.front().first, y = q.front().second;
q.pop();
for (int i = 0; i < 4; i++)
{
int a = x + dx[i], b = y + dy[i];
if (a >= 0 && a < m && b >= 0 && b < n && !used[a][b])
{
used[a][b] = true;
q.push(make_pair(a, b));
if (s[a][b] == '#')
cnt++;
if (s[a][b] == '$')
return cnt;
}
}
}
return cnt;
}
int main()
{
scanf("%d", &T);
while (T--)
{
ans = 0x3f3f3f3f;
memset(s, 0, sizeof s);
memset(used, false, sizeof used);
scanf("%d%d", &n, &m);
for (int i = 0; i < m; i++)
scanf("%s", s[i]);
for (int i = 0; i < m; i++)
for (int j = 0; j < n; j++)
if (s[i][j] == '$')
{
x = i, y = j;
ans = min(ans, (int) bfs(i, j));
ans = min(ans, bfs(i, j));
}
printf("%d\n", ans);
}
return 0;
}