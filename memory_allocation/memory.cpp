// all.cpp

#include <chrono>
#include <iostream>
#include <memory>

static const long long numInt= 100000000;

void raw() {
  auto start = std::chrono::system_clock::now();
  for ( long long i=0 ; i < numInt; ++i){
    int* tmp(new int(i));
    delete tmp;
  }
  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time: " << __FUNCTION__ << " " << dur.count() << " seconds" << std::endl;
}


void shared1() {
  auto start = std::chrono::system_clock::now();
  for ( long long i=0 ; i < numInt; ++i){
    std::shared_ptr<int> tmp(new int(i));
  }
  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time: " << __FUNCTION__ << " " << dur.count() << " seconds" << std::endl;
}

void shared2() {
  auto start = std::chrono::system_clock::now();
  for ( long long i=0 ; i < numInt; ++i){
    std::shared_ptr<int> tmp(std::make_shared<int>(i));
  }
  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time: " << __FUNCTION__ << " " << dur.count() << " seconds" << std::endl;
}

void unique1() {
  auto start = std::chrono::system_clock::now();
  for ( long long i=0 ; i < numInt; ++i){
    std::unique_ptr<int> tmp(new int(i));
  }
  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time: " << __FUNCTION__ << " " << dur.count() << " seconds" << std::endl;
}

void unique2() {
  auto start = std::chrono::system_clock::now();
  for ( long long i=0 ; i < numInt; ++i){
    std::unique_ptr<int> tmp(std::make_unique<int>(i));
  }
  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time: " << __FUNCTION__ << " " << dur.count() << " seconds" << std::endl;
}

int main(){
  raw();
  shared1();
  shared2();
  unique1();
  unique2();
}
