#include <iostream>
#include <cmath>
#include <cstdlib>
#include <array>

template <typename T, unsigned int dimension>
class SortableList {
private:
    std::array<T, dimension> sortable_array;
public:
    SortableList();
    // void reshuffle();
    // void quick_sort();
    // void merge_sort();
    // void intro_sort();

    template<typename T1, unsigned int dimension1>
    friend std::ostream &operator<<(std::ostream &ost, SortableList<T1, dimension1> &srt_list);
    
    void set_array(std::array<T, dimension> &srt_array);
};

template<typename T, unsigned int dimension>
SortableList<T, dimension>::SortableList() {
    for(T &element : this->sortable_array){
        element = T(std::rand());
    }
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
