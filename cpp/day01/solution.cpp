#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  ifstream inputFile("input.txt");

  if (!inputFile.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }

  string line = "";
  vector<int> list1;
  vector<int> list2;
  int num1 = 0;
  int num2 = 0;

  while (inputFile >> num1 >> num2) {
    list1.push_back(num1);
    list2.push_back(num2);
  }
  inputFile.close();

  sort(list1.begin(), list1.end());
  sort(list2.begin(), list2.end());

  int totalDistance = 0;
  for (size_t i = 0; i < list1.size(); ++i) {
    totalDistance += abs(list1[i] - list2[i]);
    //totalDistance += abs(static_cast<int>(list1[i] - list2[i]));
  }

  cout << "Total distance: " << totalDistance << endl;
  return 0;
}
