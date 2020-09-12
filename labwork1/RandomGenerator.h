#pragma once
#include <vector>
#include <string>

using namespace std;

class RandomGenerator {
public:
    RandomGenerator(const string& name,int N);

    int NextNumber();

    int getPrevious() const;

    void setPrevious(int number);

    string getName() const;

    int AverageNumbers() const;

private:
    vector<int> sequence;

    string name;
    
    double getRand() const;

    int N;
};
