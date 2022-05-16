#include <boost/version.hpp>
#include <boost/config.hpp>
#include <iostream>

int main(int argc,char** argv[]){
    std::cout << BOOST_VERSION << std::endl;
    std::cout<< BOOST_LIB_VERSION << std::endl;
}