#include <bits/stdc++.h>
using namespace std;

const int MAX = 305;
const int INF = 1e9;
int mv[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int danger[MAX][MAX];   // 每个格子最早被摧毁的时间
int dist[MAX][MAX];     // BFS 到达每个格子的时间

int main() {
    int m;
    cin >> m;
    // 初始化 danger 为无穷大
    for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < MAX; ++j)
            danger[i][j] = INF;

    // 读入流星并标记危险时间
    for (int i = 0; i < m; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        // 当前格子
        if (x >= 0 && x < MAX && y >= 0 && y < MAX)
            danger[x][y] = min(danger[x][y], t);
        // 四个邻域
        for (int d = 0; d < 4; ++d) {
            int nx = x + mv[d][0], ny = y + mv[d][1];
            if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX)
                danger[nx][ny] = min(danger[nx][ny], t);
        }
    }

    // BFS
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;
    if (danger[0][0] > 0) {  // 起点在时刻0未被摧毁
        dist[0][0] = 0;
        q.push({0,0});
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int cur = dist[x][y];
        if (danger[x][y] == INF) {  // 找到安全格子
            cout << cur << endl;
            return 0;
        }
        for (int d = 0; d < 4; ++d) {
            int nx = x + mv[d][0], ny = y + mv[d][1];
            if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX && dist[nx][ny] == -1) {
                if (cur + 1 < danger[nx][ny]) {  // 到达时间小于被摧毁时间
                    dist[nx][ny] = cur + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}