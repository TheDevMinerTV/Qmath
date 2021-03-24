//To speed test, edit the functions on lines 46 and 55 to some standard function and lines 66 and 76 to some qmath function.
//In this current example I'm comparing qmath::sin (lines 66 and 76) to the speed of std::sin (46 and 55).
//Results will vary per user's computer.

#include <string>
#include <iostream>
#include <chrono>
#include <random>
#include <array>
#include <memory>
#include <vector>
#include "qmath.h"

using namespace std;

int main()
{
    using namespace std::chrono;

    static const int NUM_RUNS = 10000000;

    std::vector<double> stdTimes;
    std::vector<double> qmathTimes;

    unique_ptr<array<double, NUM_RUNS> const> inputArray = [&]() {
        random_device rd;
        default_random_engine re(rd());
        uniform_real_distribution<double> rand(1, 10000);

        auto arr = make_unique<std::array<double, NUM_RUNS>>();
        for (auto &i : *arr)
        {
            i = rand(re);
        }
        return std::move(arr);
    }();

    for (auto i = 1; i < 11; i++)
    {
        //Test std::sin;
        auto stdResults = make_unique<std::array<double, NUM_RUNS>>();
        auto const stdTime = [&]() {
            auto t1 = chrono::high_resolution_clock::now();
            for (unsigned int i = 0; i < inputArray->size(); i++)
            {
                stdResults->at(i) = std::sin(2 * inputArray->at(i));
            }
            auto t2 = chrono::high_resolution_clock::now();
            return chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        }() / 1000.; // divide by 1000 to get ms
        auto std2Results = make_unique<std::array<double, NUM_RUNS>>();
        auto const std2Time = [&]() {
            auto t1 = chrono::high_resolution_clock::now();
            for (unsigned int i = 0; i < inputArray->size(); i++)
            {
                std2Results->at(i) = std::sin((float)(2 * inputArray->at(i))) + qmath::sin((float)(2 * inputArray->at(i)));
            }
            auto t2 = chrono::high_resolution_clock::now();
            return chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        }() / 1000.; // divide by 1000 to get ms

        auto GAResults = make_unique<std::array<double, NUM_RUNS>>();
        auto const GATime = [&]() { // time in ms (float)
            auto t1 = chrono::high_resolution_clock::now();
            for (unsigned int i = 0; i < inputArray->size(); i++)
            {
                GAResults->at(i) = qmath::sin(2.f * inputArray->at(i));
            }
            auto t2 = chrono::high_resolution_clock::now();
            return chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        }() / 1000.; // divide by 1000 to get ms

        auto GA2Results = make_unique<std::array<double, NUM_RUNS>>();
        auto const GA2Time = [&]() { // time in ms (float)
            auto t1 = chrono::high_resolution_clock::now();
            for (unsigned int i = 0; i < inputArray->size(); i++)
            {
                GA2Results->at(i) = qmath::sin(2.f * inputArray->at(i)) + qmath::sin(inputArray->at(i));
            }
            auto t2 = chrono::high_resolution_clock::now();
            return chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        }() / 1000.; // divide by 1000 to get ms

        stdTimes.push_back(std2Time - stdTime);
        qmathTimes.push_back(GA2Time - GATime);
    }

    std::cout << "std::   ";

    for (const double result : stdTimes)
    {
        std::printf("%.3f ms ", result);
    }

    std::cout << std::endl
              << "qmath:: ";

    for (const double result : qmathTimes)
    {
        std::printf("%.3f ms ", result);
    }

    std::cout << std::endl;

    return 0;
}
