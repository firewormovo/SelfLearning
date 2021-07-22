#ifndef DATA_RECV_H_
#define DATA_RECV_H_

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

struct student
{
    std::string name;
    int age;
    bool gender;
};


class data_recv
{
public:
    data_recv();
    ~data_recv();

    void swap_data();
private:
    static void thread_recv_data(data_recv *);
    void change_data();
    void init();


private:
    student my_student;
    student other_student;
     std::mutex m_mutex; 
};


#endif // DATA_RECV_H_