#include <iostream>
#include <fstream>
#include <tuple>
#include "gtest/gtest.h"
#include "SortableList.h"
#include "Timer.h"

template <typename T, unsigned int dimension>
std::tuple<float,float,float> test_sort_array_many_times_all_random(SortableList<T, dimension> srt_lst, float percentage = 0, int iterations = 100){
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

    std::tuple<float,float,float> result;
    result = std::make_tuple(timer_quick_sort.get_duration(), timer_heap_sort.get_duration(), timer_merge_sort.get_duration());

    return result;
}

TEST (sort_arrays_size_10_000, all_random) {

    int iterations = 100;
    float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    
    SortableList<char, 10000> *srt_lst = new SortableList<char, 10000>();
    std::tie(time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort) = test_sort_array_many_times_all_random(*srt_lst);
    float mean_time_reasult_quick_sort = time_reasult_quick_sort/iterations;
    float mean_time_reasult_heap_sort = time_reasult_heap_sort/iterations;
    float mean_time_reasult_merge_sort = time_reasult_merge_sort/iterations;
    
    std::cout<<"quick sort time:"<<std::endl;
    std::cout<<mean_time_reasult_quick_sort<< "[us]" <<std::endl;
    std::cout<<"heap sort time:"<<std::endl;
    std::cout<<mean_time_reasult_heap_sort<< "[us]" <<std::endl;
    std::cout<<"merge sort time:"<<std::endl;
    std::cout<<mean_time_reasult_merge_sort<< "[us]" <<std::endl;

    delete srt_lst;

    EXPECT_TRUE(mean_time_reasult_merge_sort < 20000);
    EXPECT_TRUE(mean_time_reasult_heap_sort < 20000);
    EXPECT_TRUE(mean_time_reasult_quick_sort < 20000);
}

TEST (sort_arrays_size_10_000, 25_percent_sorted) {

    int iterations = 100;
    float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    
    SortableList<char, 10000> *srt_lst = new SortableList<char, 10000>();
    std::tie(time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort) = test_sort_array_many_times_all_random(*srt_lst, 25);
    float mean_time_reasult_quick_sort = time_reasult_quick_sort/iterations;
    float mean_time_reasult_heap_sort = time_reasult_heap_sort/iterations;
    float mean_time_reasult_merge_sort = time_reasult_merge_sort/iterations;
    
    std::cout<<"quick sort time:"<<std::endl;
    std::cout<<mean_time_reasult_quick_sort<< "[us]" <<std::endl;
    std::cout<<"heap sort time:"<<std::endl;
    std::cout<<mean_time_reasult_heap_sort<< "[us]" <<std::endl;
    std::cout<<"merge sort time:"<<std::endl;
    std::cout<<mean_time_reasult_merge_sort<< "[us]" <<std::endl;

    delete srt_lst;

    EXPECT_TRUE(mean_time_reasult_merge_sort < 20000);
    EXPECT_TRUE(mean_time_reasult_heap_sort < 20000);
    EXPECT_TRUE(mean_time_reasult_quick_sort < 20000);
}

TEST (sort_arrays_size_10_000, 50_percent_sorted) {

    int iterations = 100;
    float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    
    SortableList<char, 10000> *srt_lst = new SortableList<char, 10000>();
    std::tie(time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort) = test_sort_array_many_times_all_random(*srt_lst, 50);
    float mean_time_reasult_quick_sort = time_reasult_quick_sort/iterations;
    float mean_time_reasult_heap_sort = time_reasult_heap_sort/iterations;
    float mean_time_reasult_merge_sort = time_reasult_merge_sort/iterations;
    
    std::cout<<"quick sort time:"<<std::endl;
    std::cout<<mean_time_reasult_quick_sort<< "[us]" <<std::endl;
    std::cout<<"heap sort time:"<<std::endl;
    std::cout<<mean_time_reasult_heap_sort<< "[us]" <<std::endl;
    std::cout<<"merge sort time:"<<std::endl;
    std::cout<<mean_time_reasult_merge_sort<< "[us]" <<std::endl;

    delete srt_lst;

    EXPECT_TRUE(mean_time_reasult_merge_sort < 20000);
    EXPECT_TRUE(mean_time_reasult_heap_sort < 20000);
    EXPECT_TRUE(mean_time_reasult_quick_sort < 20000);
}

TEST (sort_arrays_size_50_000, all_random) {

    int iterations = 100;
    float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    
    SortableList<char, 50000> *srt_lst = new SortableList<char, 50000>();
    std::tie(time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort) = test_sort_array_many_times_all_random(*srt_lst);
    float mean_time_reasult_quick_sort = time_reasult_quick_sort/iterations;
    float mean_time_reasult_heap_sort = time_reasult_heap_sort/iterations;
    float mean_time_reasult_merge_sort = time_reasult_merge_sort/iterations;
    
    std::cout<<"quick sort time:"<<std::endl;
    std::cout<<mean_time_reasult_quick_sort<< "[us]" <<std::endl;
    std::cout<<"heap sort time:"<<std::endl;
    std::cout<<mean_time_reasult_heap_sort<< "[us]" <<std::endl;
    std::cout<<"merge sort time:"<<std::endl;
    std::cout<<mean_time_reasult_merge_sort<< "[us]" <<std::endl;
    
    delete srt_lst;

    EXPECT_TRUE(mean_time_reasult_merge_sort < 100000);
    EXPECT_TRUE(mean_time_reasult_heap_sort < 100000);
    EXPECT_TRUE(mean_time_reasult_quick_sort < 100000);
}

TEST (sort_arrays_size_50_000, 25_percent_sorted) {

    int iterations = 100;
    float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    
    SortableList<char, 50000> *srt_lst = new SortableList<char, 50000>();
    std::tie(time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort) = test_sort_array_many_times_all_random(*srt_lst, 25);
    float mean_time_reasult_quick_sort = time_reasult_quick_sort/iterations;
    float mean_time_reasult_heap_sort = time_reasult_heap_sort/iterations;
    float mean_time_reasult_merge_sort = time_reasult_merge_sort/iterations;
    
    std::cout<<"quick sort time:"<<std::endl;
    std::cout<<mean_time_reasult_quick_sort<< "[us]" <<std::endl;
    std::cout<<"heap sort time:"<<std::endl;
    std::cout<<mean_time_reasult_heap_sort<< "[us]" <<std::endl;
    std::cout<<"merge sort time:"<<std::endl;
    std::cout<<mean_time_reasult_merge_sort<< "[us]" <<std::endl;
    
    delete srt_lst;

    EXPECT_TRUE(mean_time_reasult_merge_sort < 100000);
    EXPECT_TRUE(mean_time_reasult_heap_sort < 100000);
    EXPECT_TRUE(mean_time_reasult_quick_sort < 100000);
}

TEST (sort_arrays_size_50_000, 50_percent_sorted) {

    int iterations = 100;
    float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    
    SortableList<char, 50000> *srt_lst = new SortableList<char, 50000>();
    std::tie(time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort) = test_sort_array_many_times_all_random(*srt_lst, 50);
    float mean_time_reasult_quick_sort = time_reasult_quick_sort/iterations;
    float mean_time_reasult_heap_sort = time_reasult_heap_sort/iterations;
    float mean_time_reasult_merge_sort = time_reasult_merge_sort/iterations;
    
    std::cout<<"quick sort time:"<<std::endl;
    std::cout<<mean_time_reasult_quick_sort<< "[us]" <<std::endl;
    std::cout<<"heap sort time:"<<std::endl;
    std::cout<<mean_time_reasult_heap_sort<< "[us]" <<std::endl;
    std::cout<<"merge sort time:"<<std::endl;
    std::cout<<mean_time_reasult_merge_sort<< "[us]" <<std::endl;
    
    delete srt_lst;

    EXPECT_TRUE(mean_time_reasult_merge_sort < 100000);
    EXPECT_TRUE(mean_time_reasult_heap_sort < 100000);
    EXPECT_TRUE(mean_time_reasult_quick_sort < 100000);
}

TEST (sort_arrays_size_100_000, all_random) {

    int iterations = 100;
    float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    
    SortableList<char, 100000> *srt_lst = new SortableList<char, 100000>();
    std::tie(time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort) = test_sort_array_many_times_all_random(*srt_lst);
    float mean_time_reasult_quick_sort = time_reasult_quick_sort/iterations;
    float mean_time_reasult_heap_sort = time_reasult_heap_sort/iterations;
    float mean_time_reasult_merge_sort = time_reasult_merge_sort/iterations;
    
    std::cout<<"quick sort time:"<<std::endl;
    std::cout<<mean_time_reasult_quick_sort<< "[us]" <<std::endl;
    std::cout<<"heap sort time:"<<std::endl;
    std::cout<<mean_time_reasult_heap_sort<< "[us]" <<std::endl;
    std::cout<<"merge sort time:"<<std::endl;
    std::cout<<mean_time_reasult_merge_sort<< "[us]" <<std::endl;

    delete srt_lst;

    EXPECT_TRUE(mean_time_reasult_merge_sort < 200000);
    EXPECT_TRUE(mean_time_reasult_heap_sort < 200000);
    EXPECT_TRUE(mean_time_reasult_quick_sort < 200000);
}

TEST (sort_arrays_size_100_000, 25_percent_sorted) {

    int iterations = 100;
    float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    
    SortableList<char, 100000> *srt_lst = new SortableList<char, 100000>();
    std::tie(time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort) = test_sort_array_many_times_all_random(*srt_lst, 25);
    float mean_time_reasult_quick_sort = time_reasult_quick_sort/iterations;
    float mean_time_reasult_heap_sort = time_reasult_heap_sort/iterations;
    float mean_time_reasult_merge_sort = time_reasult_merge_sort/iterations;
    
    std::cout<<"quick sort time:"<<std::endl;
    std::cout<<mean_time_reasult_quick_sort<< "[us]" <<std::endl;
    std::cout<<"heap sort time:"<<std::endl;
    std::cout<<mean_time_reasult_heap_sort<< "[us]" <<std::endl;
    std::cout<<"merge sort time:"<<std::endl;
    std::cout<<mean_time_reasult_merge_sort<< "[us]" <<std::endl;

    delete srt_lst;

    EXPECT_TRUE(mean_time_reasult_merge_sort < 200000);
    EXPECT_TRUE(mean_time_reasult_heap_sort < 200000);
    EXPECT_TRUE(mean_time_reasult_quick_sort < 200000);
}

TEST (sort_arrays_size_100_000, 50_percent_sorted) {

    int iterations = 100;
    float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    
    SortableList<char, 100000> *srt_lst = new SortableList<char, 100000>();
    std::tie(time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort) = test_sort_array_many_times_all_random(*srt_lst, 50);
    float mean_time_reasult_quick_sort = time_reasult_quick_sort/iterations;
    float mean_time_reasult_heap_sort = time_reasult_heap_sort/iterations;
    float mean_time_reasult_merge_sort = time_reasult_merge_sort/iterations;
    
    std::cout<<"quick sort time:"<<std::endl;
    std::cout<<mean_time_reasult_quick_sort<< "[us]" <<std::endl;
    std::cout<<"heap sort time:"<<std::endl;
    std::cout<<mean_time_reasult_heap_sort<< "[us]" <<std::endl;
    std::cout<<"merge sort time:"<<std::endl;
    std::cout<<mean_time_reasult_merge_sort<< "[us]" <<std::endl;

    delete srt_lst;

    EXPECT_TRUE(mean_time_reasult_merge_sort < 200000);
    EXPECT_TRUE(mean_time_reasult_heap_sort < 200000);
    EXPECT_TRUE(mean_time_reasult_quick_sort < 200000);
}

TEST (sort_arrays_size_500_000, all_random) {

    int iterations = 100;
    float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    
    SortableList<char, 500000> *srt_lst = new SortableList<char, 500000>();
    std::tie(time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort) = test_sort_array_many_times_all_random(*srt_lst);
    float mean_time_reasult_quick_sort = time_reasult_quick_sort/iterations;
    float mean_time_reasult_heap_sort = time_reasult_heap_sort/iterations;
    float mean_time_reasult_merge_sort = time_reasult_merge_sort/iterations;
    
    std::cout<<"quick sort time:"<<std::endl;
    std::cout<<mean_time_reasult_quick_sort<< "[us]" <<std::endl;
    std::cout<<"heap sort time:"<<std::endl;
    std::cout<<mean_time_reasult_heap_sort<< "[us]" <<std::endl;
    std::cout<<"merge sort time:"<<std::endl;
    std::cout<<mean_time_reasult_merge_sort<< "[us]" <<std::endl;
    
    delete srt_lst;

    EXPECT_TRUE(mean_time_reasult_merge_sort < 1000000);
    EXPECT_TRUE(mean_time_reasult_heap_sort < 1000000);
    EXPECT_TRUE(mean_time_reasult_quick_sort < 1000000);
}

TEST (sort_arrays_size_1000_000, all_random) {

    int iterations = 100;
    float time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort;
    
    SortableList<char, 1000000> *srt_lst = new SortableList<char, 1000000>();
    std::tie(time_reasult_quick_sort, time_reasult_heap_sort, time_reasult_merge_sort) = test_sort_array_many_times_all_random(*srt_lst);
    float mean_time_reasult_quick_sort = time_reasult_quick_sort/iterations;
    float mean_time_reasult_heap_sort = time_reasult_heap_sort/iterations;
    float mean_time_reasult_merge_sort = time_reasult_merge_sort/iterations;
    
    std::cout<<"quick sort time:"<<std::endl;
    std::cout<<mean_time_reasult_quick_sort<< "[us]" <<std::endl;
    std::cout<<"heap sort time:"<<std::endl;
    std::cout<<mean_time_reasult_heap_sort<< "[us]" <<std::endl;
    std::cout<<"merge sort time:"<<std::endl;
    std::cout<<mean_time_reasult_merge_sort<< "[us]" <<std::endl;

    delete srt_lst;

    EXPECT_TRUE(mean_time_reasult_merge_sort < 2000000);
    EXPECT_TRUE(mean_time_reasult_heap_sort < 2000000);
    EXPECT_TRUE(mean_time_reasult_quick_sort < 2000000);
}
