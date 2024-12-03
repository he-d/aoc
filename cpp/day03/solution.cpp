#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

using namespace std;

int main() {
  ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    cerr << "Error opening the file!" << endl;
    return 1;
  }

  int mulResult = 0;
  string line;
  smatch matches;
  regex reg(R"(\((\d+),(\d+)\))");

  while (getline(inputFile, line)) {
    stringstream lineStream(line);

    while (lineStream >> line) {
      while (regex_search(line, matches, reg)) {
        mulResult += stoi(matches[1].str());
        mulResult += stoi(matches[2].str());
        line = matches.suffix().str();
      }
    }
  }
  inputFile.close();

  cout << "The sum of all multiplications is: " << mulResult << endl;

  return 0;
}
