#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <memory>
#include <chrono>

class Benchmark
{
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start_point;

    public:
        Benchmark(){
            this->start_point = std::chrono::high_resolution_clock::now();
        }

        ~Benchmark(){
            Stop();
        }

        float Stop(){
            auto end_point = std::chrono::high_resolution_clock::now();

            auto start = std::chrono::time_point_cast<std::chrono::microseconds>(this->start_point).time_since_epoch().count();
            auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count();
            auto duration = end - start;
            std::cout << "time: " << duration << "[us]" << std::endl;
            return duration;
        }
    
};

#endif //TIMER_H