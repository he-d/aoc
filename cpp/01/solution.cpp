#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream input("input.txt");
    if (!input.is_open()) {
        cerr << "Error: Could not open input.txt" << endl;
        return 1;
    }

    int position = 50;
    int count = 0;
    string line;

    while (getline(input, line)) {
        if (line.empty()) continue;

        char direction = line[0];
        int steps = stoi(line.substr(1));

        if (direction == 'L') {
            position -= steps;
            while (position < 0) position += 100;
        } else if (direction == 'R') {
            position += steps;
            while (position >= 100) position -= 100;
        }

        if (position == 0) {
            count++;
        }
    }

    cout << "The password is: " << count << endl;
    return 0;
}
