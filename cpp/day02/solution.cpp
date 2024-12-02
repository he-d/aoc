#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

using namespace std;
bool comp(int a, int b) { return a > b; }

bool checkReportSafety(vector<int> report) {
  bool result = false;
  int distanceLimit = 3;

  if (is_sorted(report.begin(), report.end()) ||
      is_sorted(report.begin(), report.end(), comp)) {

    for (size_t i = 1; i < report.size(); ++i) {
      if ((abs(report[i] - report[i - 1]) > distanceLimit) ||
          (report[i] == report[i - 1])) {
        return false;
      }
    }
    result = true;
  }

  return result;
}

int main() {
  ifstream inputFile("input.txt");

  if (!inputFile.is_open()) {
    cerr << "Error opening the file!";
    return 1;
  }

  string line = "";
  int noOfSafeReports = 0;

  while (getline(inputFile, line)) {
    stringstream lineStream(line);
    vector<int> report(istream_iterator<int>(lineStream), {});
    if (checkReportSafety(report)) {
      ++noOfSafeReports;
    }
  }

  inputFile.close();

  cout << "Number of safe reports: " << noOfSafeReports << endl;

  return 0;
}
