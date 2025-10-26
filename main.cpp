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

vector<string> read_lines(string path){
    ifstream in(path);
    vector<string> lines;
    string s;
    lines.reserve(20000);
    while (getline(in, s)) lines.push_back(s);
    return lines;
}

int main() {
    vector<string> lines = read_lines("codes.txt");
    if (lines.empty()) {
      cerr << "ERROR: couldn't read codes.txt\n";
      return 1;
    }

    long long vec_read_us, lst_read_us, sor_read_us;
    long long vec_sort_us, lst_sort_us, sor_sort_us = -1;
    long long vec_ins_us,  lst_ins_us,  sor_ins_us;
    long long vec_del_us,  lst_del_us,  sor_del_us;

    //Read section
    {
        auto start = high_resolution_clock::now();
        vector<string> vec; vec.reserve(lines.size());
        for (const auto& x : lines) vec.push_back(x);
        auto end = high_resolution_clock::now();
        vec_read_us = duration_cast<microseconds>(end - start).count();
    }
    { 
        auto start = high_resolution_clock::now();
        list<string> lst;
        for (const auto& x : lines) lst.push_back(x);
        auto end = high_resolution_clock::now();
        lst_read_us = duration_cast<microseconds>(end - start).count();
    }
    { 
        auto start = high_resolution_clock::now();
        set<string> st(lines.begin(), lines.end());
        auto end = high_resolution_clock::now();
        sor_read_us = duration_cast<microseconds>(end - start).count();
    }

    cout << left << setw(12) << "Operation"
         << setw(12) << "Vector(us)"
         << setw(12) << "List(us)"
         << setw(12) << "Set(us)" << "\n";
    cout << left << setw(12) << "Read"
         << setw(12) << vec_read_us
         << setw(12) << lst_read_us
         << setw(12) << sor_read_us << "\n";

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/