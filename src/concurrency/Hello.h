#pragma once

#include <future>
#include <iostream>
#include <thread>

void hello()
{
    std::cout << "[" << std::this_thread::get_id() << "] "
              << "Hello world of concurrency: " << std::thread::hardware_concurrency() << "\n";
}

void print_hello(int id, std::shared_future<std::string> sf)
{
    std::cout << "[" << id << "] " << sf.get() << "\n";
}
