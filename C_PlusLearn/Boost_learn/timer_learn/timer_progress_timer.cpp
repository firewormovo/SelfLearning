#include <boost/progress.hpp>
#include <iostream>

using namespace boost;
using namespace std;

int main(int argc, char **argv[]) {
  {
    progress_timer t;
    int i = 10;
    while (i > 0) {
      int a = i * 3;
      i -= 1;
    }
  }
  {
    progress_timer t;
    int i = 1;
    while (i < 30) {
      int a = i * i;
      i += 1;
    }
  }
}
