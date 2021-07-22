
#include "data_recv.h"
#include <iostream>
#include "unistd.h"
int main()
{
    data_recv my_data;
    while (1)
    {
        my_data.swap_data();
        int a = 0;
        int b = 1;
        a = b;
        usleep(2);
    }
    
}