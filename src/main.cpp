#include <iostream>
#include <fstream>
#include "SortableList.h"


int main() {

std::cout<<"hello"<<std::endl;

SortableList<float, 3> srt_lst;
std::array<float, 3> new_array = {1.1, 22.4, 123.54};
std::cout<<srt_lst<<std::endl;
srt_lst.set_array(new_array);
std::cout<<srt_lst<<std::endl;

new_array[0]= 69;
std::cout<<srt_lst;
}
