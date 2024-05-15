#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int x;
    int y;
};

int dir[4][2] = {
    {0, 1}, {0, -1},
    {1, 0}, {-1, 0}
};

bool isValidSafeness(int **grid, int n, int sVal) {
    if (grid[0][0] < sVal || grid[n-1][n-1] < sVal) return false;
    struct Node tq[401*401] = {0};  // Adjusted the size to handle larger grids
    bool v[401][401] = {0};  // Adjusted the size to handle larger grids
    int head = 0;
    int rear = -1;
    tq[++rear] = (struct Node){0, 0};
    v[0][0] = 1;

    while (rear >= head) {
        struct Node curr = tq[head++];
        if (curr.x == n - 1 && curr.y == n - 1) return true;

        for (int i = 0; i < 4; i++) {
            int dx = curr.x + dir[i][0];
            int dy = curr.y + dir[i][1];
            if (dx >= 0 && dy >= 0 && dx < n && dy < n && v[dy][dx] == 0 && grid[dy][dx] >= sVal) {
                v[dy][dx] = 1;
                tq[++rear] = (struct Node){dx, dy};
            }
        }
    }
    return false;
}

int maximumSafenessFactor(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int head = 0;
    int rear = -1;
    struct Node q[401*401] = {0};  // Adjusted the size to handle larger grids

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                q[++rear] = (struct Node){j, i};
                grid[i][j] = 0;
            } else {
                grid[i][j] = -1;
            }
        }
    }

    while (rear >= head) {
        int size = rear - head + 1;
        while (size-- > 0) {
            struct Node curr = q[head++];
            for (int i = 0; i < 4; i++) {
                int dx = curr.x + dir[i][0];
                int dy = curr.y + dir[i][1];
                int val = grid[curr.y][curr.x];
                if (dx >= 0 && dy >= 0 && dx < n && dy < n && grid[dy][dx] == -1) {
                    grid[dy][dx] = val + 1;
                    q[++rear] = (struct Node){dx, dy};
                }
            }
        }
    }

    int start = 0;
    int end = 0;
    int ret = -1;
    int mid;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (end < grid[i][j]) end = grid[i][j];
        }
    }

    while (end >= start) {
        mid = start + (end - start) / 2;
        if (isValidSafeness(grid, n, mid)) {
            ret = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return ret;
}
