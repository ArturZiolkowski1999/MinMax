#include <iostream>
#include <fstream>
#include "SortableList.h"
#include "Timer.h"


int main() {

std::cout<<"hello"<<std::endl;
SortableList<double, 4> srt_lst;

std::cout<<"quick sort time:"<<std::endl;
{
    Benchmark timer;
    srt_lst.quick_sort();
    
}
    srt_lst.reshuffle();
    std::cout<<"merge sort time:"<<std::endl;
{
    Benchmark timer;
    srt_lst.merge_sort();
}
//     srt_lst.reshuffle();
//     std::cout<<"insertion sort time:"<<std::endl;
// {
//     Benchmark timer;
//     srt_lst.insertion_sort();
//     // std::cout<<srt_lst;
// }

    srt_lst.reshuffle();
    std::cout<<"heap sort time:"<<std::endl;
{
    Benchmark timer;
    srt_lst.heap_sort();
    // std::cout<<srt_lst;
}

    srt_lst.reshuffle();
    std::cout<<"intro sort time:"<<std::endl;
{
    Benchmark timer;
    srt_lst.intro_sort();
    // std::cout<<srt_lst;
}
}
