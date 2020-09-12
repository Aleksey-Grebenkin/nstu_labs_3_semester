#include "GeneratorWithStep.h"
#include <vector>
#include <string>
#include<iostream>

using namespace std;

GeneratorWithStep::GeneratorWithStep(const string& name,double first_number, double step, int N)
{
    if (N <= 0)
        throw invalid_argument("invalid variable value");
    sequence.push_back(first_number);
    this->name = name;
    this->step = step;

    this->N = N;

}

double GeneratorWithStep::NextNumber()
{
    double res = this->getPrevious() + this->step;
    sequence.push_back(res);

    return res;
}

double GeneratorWithStep::getPrevious() const
{
    if (sequence.empty())
    {
        return 0.0;
    }

    return sequence[sequence.size() - 1];
}

void GeneratorWithStep::setPrevious(double number)
{
    sequence.clear();
    sequence.push_back(number);
}

string GeneratorWithStep::getName() const
{
    return this->name;
}

double GeneratorWithStep::AverageNumbers() const
{
    if (N > sequence.size())
        throw out_of_range("invalid variable value");
    double sum = 0.0;

    int l = sequence.size();
    for (int i = l-1; i > (l - N - 1) ; i--)
    {
        sum += sequence[i];
    }
    return  sum / N;
}
