#pragma once
#include <vector>
#include <string>

using namespace std;

class GeneratorWithStep
{
public:
    GeneratorWithStep(const string& name, double first_number, double step, int N);
    double NextNumber();

    double getPrevious() const;

    void setPrevious(double number);

    string getName() const;

    double AverageNumbers() const;

private:
    vector<double> sequence;

    string name;

    double step;
    
    int N;
};
