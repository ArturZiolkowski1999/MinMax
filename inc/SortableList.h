#ifndef SORTABLE_LIST_H
#define SORTABLE_LIST_H

#include <iostream>
#include <cstdlib>
#include <array>
#include <algorithm>
#include <cmath>

template <typename T, unsigned int dimension>
class SortableList {
private:
    std::array<T, dimension> sortable_array;
    void merge(int const left, int const mid, int const right);
    void heapify(int const size, int const root);
    void intro_sort_utility(int const begin, int const end, int const depth_limit);
public:
    SortableList();
    void reshuffle();
    void quick_sort(int const begin = 0, int const end = int(dimension-1));
    void merge_sort(int const begin = 0, int const end = int(dimension-1));
    void insertion_sort(int const begin = 0, int const end = int(dimension-1));
    void heap_sort(int const size = int(dimension));
    //TODO: correct introsort imprementation !!!
    void intro_sort(int const begin = 0, int const end = int(dimension-1));

    template<typename T1, unsigned int dimension1>
    friend std::ostream &operator<<(std::ostream &ost, SortableList<T1, dimension1> &srt_list);
    
    void set_array(std::array<T, dimension> &srt_array);
    //TODO: operator = for array and SortableList
};

template<typename T, unsigned int dimension>
SortableList<T, dimension>::SortableList() {
    this->reshuffle();
}

template<typename T, unsigned int dimension>
std::ostream &operator<<(std::ostream &ost, SortableList<T, dimension> &srt_list) {
    for(T &element : srt_list.sortable_array){
        ost << element << std::endl;
    }
    return ost;
}

template<typename T, unsigned int dimension>
void SortableList<T, dimension>::set_array(std::array<T, dimension> &srt_array) {
    this->sortable_array = srt_array;
}

template<typename T, unsigned int dimension>
void SortableList<T, dimension>::reshuffle() {
    std::generate(this->sortable_array.begin(), this->sortable_array.end(), std::rand);
}

template<typename T, unsigned int dimension>
void SortableList<T, dimension>::quick_sort(int const begin, int const end) {  
    
    int left_index = begin - 1;
    int right_index = end + 1;
    T pivot = this->sortable_array[(begin+end)/2];
    //TODO: while without true
    while (true){
        while(pivot > this->sortable_array[++left_index]);
        while(pivot < this->sortable_array[--right_index]);
        if(left_index <= right_index){
            std::swap(this->sortable_array[left_index], this->sortable_array[right_index]);
        }else{
            break;
        }
    } 
    if (right_index > begin){
        quick_sort(begin, right_index);
    }
    if (left_index < end){
        quick_sort(left_index, end);
    }
}

template<typename T, unsigned int dimension>
void SortableList<T, dimension>::merge(int const left, int const mid, int const right) {  
    
    int const sub_array_one = mid - left + 1;
    int const sub_array_two = right - mid;

    // create temp arrays, and fill them

    T *left_array = new T[sub_array_one];
    T *right_array = new T[sub_array_two];

    for (int i = 0; i < sub_array_one; ++i){
        left_array[i] = this->sortable_array[left + i];
    }
    for (int j = 0; j < sub_array_two; ++j){
        right_array[j] = this->sortable_array[mid + 1 + j];
    }

    int index_of_subarray_one = 0;
    int index_of_subarray_two = 0;
    int index_of_merged_array = left;

    // merge left and right array
    while (index_of_subarray_one < sub_array_one && index_of_subarray_two < sub_array_two){
        if (left_array[index_of_subarray_one] <= right_array[index_of_subarray_two]){
            this->sortable_array[index_of_merged_array] = left_array[index_of_subarray_one];
            index_of_subarray_one++;
        }else{
            this->sortable_array[index_of_merged_array] = right_array[index_of_subarray_two];
            index_of_subarray_two++;
        }
        index_of_merged_array++;
    }

    // copy remainng elements of left array
    while(index_of_subarray_one < sub_array_one){
        this->sortable_array[index_of_merged_array] = left_array[index_of_subarray_one];
        index_of_subarray_one++;
        index_of_merged_array++;
    } 

    // copy remainng elements of right array
    while(index_of_subarray_two < sub_array_two){
        this->sortable_array[index_of_merged_array] = right_array[index_of_subarray_two];
        index_of_subarray_two++;
        index_of_merged_array++;
    } 
}

template<typename T, unsigned int dimension>
void SortableList<T, dimension>::merge_sort(int const begin, int const end) {  
    if (begin >= end){
        return;
    }
    int const mid = begin + (end - begin) / 2;
    merge_sort(begin, mid);
    merge_sort(mid + 1, end);
    merge(begin, mid, end);
}

template<typename T, unsigned int dimension>
void SortableList<T, dimension>::insertion_sort(int const begin, int const end) {  
    
    // int key, j;
    for (int i = begin + 1; i <= end; ++i){
        int key = this->sortable_array[i];
        int j = i - 1;
        while (j >= begin && this->sortable_array[j] > key){
            this->sortable_array[j+1] = this->sortable_array[j];
            j--;
        }
        this->sortable_array[j+1] = key;
    }
    return;
}

template<typename T, unsigned int dimension>
void SortableList<T, dimension>::heap_sort(int const size) {  
    for (int i = size/2 - 1; i >= 0; --i){
        heapify(size, i);
    }

    for (int i = size - 1; i > 0; --i){
        std::swap(this->sortable_array[0], this->sortable_array[i]);
        heapify(i,0);
    }
}

template<typename T, unsigned int dimension>
void SortableList<T, dimension>::heapify(int const size, int const root) {  
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && this->sortable_array[left] > this->sortable_array[largest]){
        largest = left;
    }

    if (right < size && this->sortable_array[right] > this->sortable_array[largest]){
        largest = right;
    }

    if(largest != root){
        std::swap(this->sortable_array[root], this->sortable_array[largest]);
        heapify(size, largest);
    }
}

template<typename T, unsigned int dimension>
void SortableList<T, dimension>::intro_sort_utility(int const begin, int const end, int const depth_limit) {  
    int size = end - begin;

    if (size < 16){
        insertion_sort(begin, end);
        return;
    }else if (depth_limit == 0){
        heap_sort();
    }else{
        quick_sort();
    }
}

template<typename T, unsigned int dimension>
void SortableList<T, dimension>::intro_sort(int const begin, int const end) {  
    int const depth_limit = 2 * std::log(end - begin);
    intro_sort_utility(begin, end, depth_limit);
    return;
}
#endif //SORTABLE_LIST_H