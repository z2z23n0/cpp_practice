//
// Created by Zeno on 2020/3/22.
//
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <iterator>

using namespace std;

int main()
{
    std::istream_iterator<double> in(std::cin), eof;
    std::vector<double> v(in, eof);

    return 0;
}
