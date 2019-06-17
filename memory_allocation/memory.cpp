// memory.cpp

#include <chrono>
#include <iostream>
#include <memory>

#include "utils/stop_watch.hpp"

void raw(uint64_t n) {
  lsilveira::StopWatch stopwatch(__FUNCTION__);
  for (uint64_t i = 0 ; i < n; ++i){
    int* tmp(new int(i));
    delete tmp;
  }
}

void shared(uint64_t n) {
  lsilveira::StopWatch stopwatch(__FUNCTION__);
  for (uint64_t i = 0 ; i < n; ++i){
    std::shared_ptr<int> tmp(new int(i));
  }
}

void make_shared(uint64_t n) {
  lsilveira::StopWatch stopwatch(__FUNCTION__);
  for (uint64_t i = 0 ; i < n; ++i){
    std::shared_ptr<int> tmp(std::make_shared<int>(i));
  }
}

void unique(uint64_t n) {
  lsilveira::StopWatch stopwatch(__FUNCTION__);
  for (uint64_t i = 0 ; i < n; ++i){
    std::unique_ptr<int> tmp(new int(i));
  }
}

void make_unique(uint64_t n) {
  lsilveira::StopWatch stopwatch(__FUNCTION__);
  for (uint64_t i = 0 ; i < n; ++i){
    std::unique_ptr<int> tmp(std::make_unique<int>(i));
  }
}

int main(){
  int n = 100000000;
  raw(n);
  shared(n);
  make_shared(n);
  unique(n);
  make_unique(n);
}
