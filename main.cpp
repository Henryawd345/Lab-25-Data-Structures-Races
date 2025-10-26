#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<string> read_lines(string &path){
    ifstream in(path);
    vector<string> lines;
    string s;
    lines.reserve(20000);
    while (getline(in, s)) lines.push_back(s);
    return lines;
}

int main() {
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/