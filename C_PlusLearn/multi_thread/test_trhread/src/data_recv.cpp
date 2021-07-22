#include "data_recv.h"

data_recv::data_recv()
{
    // 初始化
    my_student.name = "";
    my_student.age = 0;
    my_student.gender = 0;

    init();
}

data_recv::~data_recv()
{

}

void data_recv::thread_recv_data(data_recv* arg)
{
    arg->change_data();
    
}

void data_recv::change_data()
{
    int count = 0;
    
    while (1)
    {
        std::string name = "tttt";
        bool gender = 1;
        if(count % 10 == 0)
        {
            count = 10;
            name = "xxxxx";
            gender = 1;
        }
        {
        std::lock_guard<std::mutex> lg(m_mutex);
        my_student.name = name;
        my_student.age = count;
        my_student.gender = gender;
        
        // std::cout << "name:"<<my_student.name<<"\n"
        //         << "age:" << my_student.age<<"\n"
        //         << "gender:"<< my_student.gender<<"\n"
        //         << "--------------\n";
        count++;
        }

    }
}

void data_recv::init()
{
    std::thread t1(thread_recv_data,this);
    t1.detach();
}

void data_recv::swap_data()
{
    {
        std::lock_guard<std::mutex> lg(m_mutex);
        other_student.name = my_student.name;
        other_student.age = my_student.age ;
        other_student.gender = my_student.gender;
        
        std::cout << "name:"<<other_student.name<<"\n"
                << "age:" << other_student.age<<"\n"
                << "gender:"<< other_student.gender<<"\n"
                << "--------------\n";
    }
}