#include <iostream>
#include <fstream>
#include "SortableList.h"
#include "Timer.h"

template <typename T, unsigned int dimension>
std::tuple<float,float,float> test_sort_array_many_times(SortableList<T, dimension> srt_lst, float percentage = 0, int iterations = 100){
    Benchmark timer_quick_sort;
    Benchmark timer_merge_sort;
    Benchmark timer_heap_sort;
    
    for(int i = 0; i < iterations; ++i){
        // quick sort
        srt_lst.reshuffle(percentage);
        timer_quick_sort.Start();
        srt_lst.quick_sort();
        timer_quick_sort.Stop();
        // heap sort
        srt_lst.reshuffle(percentage);
        timer_heap_sort.Start();
        srt_lst.heap_sort();
        timer_heap_sort.Stop();
        // merge sort
        srt_lst.reshuffle(percentage);
        timer_merge_sort.Start();
        srt_lst.merge_sort();
        timer_merge_sort.Stop();
    }

    float mean_time_reasult_quick_sort = timer_quick_sort.get_duration()/iterations;
    float mean_time_reasult_heap_sort = timer_heap_sort.get_duration()/iterations;
    float mean_time_reasult_merge_sort = timer_merge_sort.get_duration()/iterations;

    std::cout<< percentage<<" proc sorted "<< dimension <<" elements:"<<std::endl;
    std::cout<<"quick sort time:"<<std::endl;
    std::cout<<mean_time_reasult_quick_sort<< "[us]" <<std::endl;
    std::cout<<"heap sort time:"<<std::endl;
    std::cout<<mean_time_reasult_heap_sort<< "[us]" <<std::endl;
    std::cout<<"merge sort time:"<<std::endl;
    std::cout<<mean_time_reasult_merge_sort<< "[us]" <<std::endl;
    return std::make_tuple(timer_quick_sort.get_duration(), timer_heap_sort.get_duration(), timer_merge_sort.get_duration());;
}

int main() {


    {
    int iterations = 100;
    float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    SortableList<char, 1000000> *srt_lst = new SortableList<char, 1000000>();
    test_sort_array_many_times(*srt_lst, 50);
    delete srt_lst;
    srt_lst = NULL;
    }

    // {
    // int iterations = 100;
    // float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    
    // SortableList<char, 50000> *srt_lst = new SortableList<char, 50000>();
    // test_sort_array_many_times(*srt_lst, 50);
    // delete srt_lst;
    // srt_lst = NULL;
    // }

    // {
    // int iterations = 100;
    // float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    
    // SortableList<char, 500000> *srt_lst = new SortableList<char, 500000>();
    // test_sort_array_many_times(*srt_lst, 50);
    // delete srt_lst;
    // srt_lst = NULL;
    // }

    // {
    // int iterations = 100;
    // float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    
    // SortableList<char, 1000000> *srt_lst = new SortableList<char, 1000000>();
    // test_sort_array_many_times(*srt_lst, 50);
    // delete srt_lst;
    // srt_lst = NULL;
    // }





// float result;

// std::cout<<"hello"<<std::endl;
// SortableList<int, 20> srt_lst;

// std::cout<<"quick sort time:"<<std::endl;
// {
//     Benchmark timer;
//     srt_lst.quick_sort();
//     result = timer.Stop(); 
//     srt_lst.reshuffle(80);
//     std::cout <<  srt_lst << std::endl;

// }
// std::cout<<result<< "[us]" <<std::endl;


//     srt_lst.reshuffle();
//     std::cout<<"merge sort time:"<<std::endl;
// {
//     Benchmark timer;
//     srt_lst.merge_sort();
//     result = timer.Stop();
// }
// std::cout<<result<< "[us]" <<std::endl;

//     srt_lst.reshuffle();
//     std::cout<<"insertion sort time:"<<std::endl;
// {
//     Benchmark timer;
//     srt_lst.insertion_sort();
//     result = timer.Stop();
//     // std::cout<<srt_lst;
// }
// std::cout<<result<< "[us]" <<std::endl;

//     srt_lst.reshuffle();
//     std::cout<<"heap sort time:"<<std::endl;
// {
//     Benchmark timer;
//     srt_lst.heap_sort();
//     result = timer.Stop();
//     // std::cout<<srt_lst;
// }
// std::cout<<result<< "[us]" <<std::endl;
}
