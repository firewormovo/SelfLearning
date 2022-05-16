#include <boost/timer.hpp>
#include <iostream>

using namespace boost;
using namespace std;

/**
 * @description:  timer use learn: timer class is simple and only has one preivate param
 * @description: It realizes the encapsulation of timing function
 * @param {int} argc
 * @param {char**} argv
 * @return {*}
 */
int main(int argc, char** argv[])
{
    timer t;

    cout << "max timespan:" << t.elapsed_max() / 3600 << "h" << endl;

    cout << "min timespan:" << t.elapsed_min() << "s" << endl;

    cout << "now time elpased:" << t.elapsed() << "s" << endl;
}