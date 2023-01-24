#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <chrono>

class Benchmark {
    public:
        Benchmark() {
            std::cout << "[Benchmark::start]\n";
            m_Bench_start = std::chrono::high_resolution_clock::now();
        }
        ~Benchmark() {
            if(!is_stopped)
                stop();
        }
        void stop() {
            auto _Bench_end = std::chrono::high_resolution_clock::now();
            auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_Bench_start).time_since_epoch().count();
            auto end = std::chrono::time_point_cast<std::chrono::microseconds>(_Bench_end).time_since_epoch().count();
            auto duration = end - start;
            printf_s("[Benchmark::stop]");
            printf_s("[Benchark::duration]:%d microseconds\n", duration);
            is_stopped = true;
        }
    private:
        bool is_stopped = false;
        std::chrono::time_point<std::chrono::high_resolution_clock> m_Bench_start;
};

#endif //!BENCHMARK_HPP