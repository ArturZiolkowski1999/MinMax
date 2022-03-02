#include <iostream>
#include <fstream>
#include "SortableList.h"
#include "Timer.h"


int main() {

std::cout<<"hello"<<std::endl;
SortableList<double, 5000> srt_lst;

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
    srt_lst.reshuffle();

}
