#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct Node {
    int x, y;
    int g, h; // g = cost from start, h = heuristic (Manhattan)
    Node* parent;

    Node(int x, int y, int g, int h, Node* parent = nullptr)
        : x(x), y(y), g(g), h(h), parent(parent) {}

    int f() const { return g + h; }

    // For priority queue
    bool operator>(const Node& other) const {
        return f() > other.f();
    }
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isValid(int x, int y, int n, int m, const vector<vector<int>>& grid) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0;
}

void reconstructPath(Node* end) {
    vector<pair<int, int>> path;
    while (end) {
        path.push_back({end->x, end->y});
        end = end->parent;
    }
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (auto& p : path)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;
}

void aStar(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    int n = grid.size(), m = grid[0].size();
    priority_queue<Node, vector<Node>, greater<>> pq;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    pq.push(Node(start.first, start.second, 0, manhattan(start.first, start.second, goal.first, goal.second)));

    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        if (visited[curr.x][curr.y]) continue;
        visited[curr.x][curr.y] = true;

        if (curr.x == goal.first && curr.y == goal.second) {
            cout << "Reached goal with cost: " << curr.f() << endl;
            reconstructPath(&curr);
            return;
        }

        for (int d = 0; d < 4; d++) {
            int nx = curr.x + dx[d];
            int ny = curr.y + dy[d];

            if (isValid(nx, ny, n, m, grid) && !visited[nx][ny]) {
                int newG = curr.g + 1;
                int newH = manhattan(nx, ny, goal.first, goal.second);
                pq.push(Node(nx, ny, newG, newH, new Node(curr)));
            }
        }
    }

    cout << "No path found." << endl;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> goal = {4, 4};

    aStar(grid, start, goal);

    return 0;
}
