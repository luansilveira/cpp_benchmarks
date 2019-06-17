
#ifndef UTILS_STOPWATCH_H_
#define UTILS_STOPWATCH_H_

#include <string>
#include <chrono>
#include <iostream>

namespace lsilveira {
class StopWatch {
 public:
    StopWatch(const std::string &name);
    ~StopWatch();

 private:
    using T = std::chrono::system_clock::time_point;
    static T Now();

    std::string name_;
    T start_;
};
}  // namespace lsilveira

#endif  // UTILS_STOPWATCH_H_
