
#include "utils/stop_watch.hpp"

namespace lsilveira {
 StopWatch::StopWatch(const std::string &name)
     : name_(name),
       start_{Now()} {}

  StopWatch::~StopWatch() {
      std::chrono::duration<double> dur = Now() - start_;
      std::cout << name_ << " " << dur.count() << " seconds" << std::endl;
  }


  StopWatch::T StopWatch::Now() {
      return std::chrono::system_clock::now();
  }
}  // namespace lsilveira
