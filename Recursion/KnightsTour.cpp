#include <iostream>
using namespace std;

#define MAXSIZE 9
#define MARK 1
#define UNMARK 0

typedef struct Point {
  int x, y;
} point;

point direaction[8] = {{1, -2}, {2, -1}, {2, 1},   {1, 2},
                       {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

int board[MAXSIZE][MAXSIZE], path[MAXSIZE][MAXSIZE];

int KnightTour(int m, int n, point pos, int counter);
int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    point start;
    int m, n, s, t;
    cin >> m >> n >> s >> t;
    start.x = t - 1;
    start.y = s - 1;
    for (int j = 0; j < MAXSIZE; j++) {
      for (int k = 0; k < MAXSIZE; k++) {
        board[j][k] = UNMARK;
      }
    }
    board[start.y][start.x] = MARK;
    path[start.y][start.x] = 1;
    if (KnightTour(m, n, start, 1)) {
      cout << 1 << endl;
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < n; k++) {
          cout << path[j][k] << " ";
        }
        cout << "\n";
      }
    } else {
      cout << 0 << endl;
    }
  }
}

int KnightTour(int m, int n, point pos, int counter) {
  point next;

  if (counter == m * n) {
    return 1;
  }
  for (int i = 0; i < 8; i++) {
    next.x = pos.x + direaction[i].x;
    next.y = pos.y + direaction[i].y;
    if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < m &&
        board[next.y][next.x] != MARK) {
      board[next.y][next.x] = MARK;
      path[next.y][next.x] = counter + 1;
      if (KnightTour(m, n, next, counter + 1)) {
        return 1;
      }
      board[next.y][next.x] = UNMARK;
    }
  }
  return 0;
}