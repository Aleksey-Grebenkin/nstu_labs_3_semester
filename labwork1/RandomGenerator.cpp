#include "RandomGenerator.h"
#include <stdexcept>
#include<iostream>
using namespace std;
RandomGenerator::RandomGenerator(const string& name, int N)
{
    if (N <= 0)
        throw invalid_argument("invalid variable value");
    this->name = name;
    this->N = N;
}

int RandomGenerator::NextNumber()
{
    double res = this->getRand();
    sequence.push_back(res);

    return res;
}

int RandomGenerator::getPrevious() const
{
    if (sequence.empty())
    {
        return 0;
    }
    
    return sequence[sequence.size() - 1];
}

void RandomGenerator::setPrevious(int number)
{
    sequence.clear();
    sequence.push_back(number);
    srand(number);
}

string RandomGenerator::getName() const
{
    return this->name;
}

int RandomGenerator::AverageNumbers() const
{
    int sum = 0;
    if (N > sequence.size())
        throw out_of_range("invalid variable value");

    for (int i = sequence.size() - 1; i + 1 > sequence.size()  - N; i--)
    {
        sum += sequence[i];
    }
    return sum / N;
}

double RandomGenerator::getRand() const
{
    return rand();
}
