#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool checkDirection(const vector<string> &grid, int x, int y, int dirX,
                    int dirY, const string &word) {
  int n = grid.size();
  int m = grid[0].size();
  for (int i = 0; i < word.size(); ++i) {
    int nx = x + i * dirX;
    int ny = y + i * dirY;
    if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != word[i]) {
      return false;
    }
  }
  return true;
}

int countOccurrences(const vector<string> &grid, const string &word) {
  int count = 0;
  int n = grid.size();
  int m = grid[0].size();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < 8; ++k) {
        if (checkDirection(grid, i, j, dx[k], dy[k], word)) {
          ++count;
        }
      }
    }
  }
  return count;
}

int main() {
  vector<string> grid;
  string filename = "input.txt";
  string line;

  ifstream inputFile(filename);
  if (!inputFile.is_open()) {
    cerr << "Error opening the file!" << endl;
    return 1;
  }

  while (getline(inputFile, line)) {
    grid.push_back(line);
  }
  inputFile.close();

  string word = "XMAS";
  int result = countOccurrences(grid, word);

  cout << "Total occurrences of " << word << ": " << result << endl;

  return 0;
}
