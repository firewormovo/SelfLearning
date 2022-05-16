#include <boost/progress.hpp>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace boost;
using namespace std;

int main(int argc, char** argv[]) {
  vector<string> v(100);
  // 1.pure loop
  {
    ofstream fs("./test.txt");

    progress_display pd(v.size());

    for (auto& x : v) {
      fs << x << endl;
      ++pd;
    }
  }
  // 2.loop contain other out stream,it will become confusion
  {
    ofstream fs("./test.txt");

    progress_display pd(v.size());

    for (auto& x : v) {
      fs << x << endl;
      cout << "x.size():" << x.size() << endl;
      ++pd;
    }
  }
  // 3.according 2. do some change,but this way only keep the percent of progress
  {
    vector<string> v1(100, "str");
    ofstream fs("./test.txt");

    progress_display pd(v1.size());

    for (auto pos = v1.begin(); pos != v1.end(); ++pos) {
      fs << *pos << endl;
      pd.restart(v1.size());
      pd += (pos - v1.begin() + 1);
      cout << endl << "pose size():" << pos->size() << endl;
    }
  }
}