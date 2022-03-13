#include <iostream>
#include <fstream>
#include "SortableList.h"
#include "Timer.h"


int main() {

float result;

std::cout<<"hello"<<std::endl;
SortableList<int, 10000> srt_lst;

std::cout<<"quick sort time:"<<std::endl;
{
    Benchmark timer;
    srt_lst.quick_sort();
    result = timer.Stop();  
}
std::cout<<result<< "[us]" <<std::endl;


    srt_lst.reshuffle();
    std::cout<<"merge sort time:"<<std::endl;
{
    Benchmark timer;
    srt_lst.merge_sort();
    result = timer.Stop();
}
std::cout<<result<< "[us]" <<std::endl;

    srt_lst.reshuffle();
    std::cout<<"insertion sort time:"<<std::endl;
{
    Benchmark timer;
    srt_lst.insertion_sort();
    result = timer.Stop();
    // std::cout<<srt_lst;
}
std::cout<<result<< "[us]" <<std::endl;

    srt_lst.reshuffle();
    std::cout<<"heap sort time:"<<std::endl;
{
    Benchmark timer;
    srt_lst.heap_sort();
    result = timer.Stop();
    // std::cout<<srt_lst;
}
std::cout<<result<< "[us]" <<std::endl;
}
