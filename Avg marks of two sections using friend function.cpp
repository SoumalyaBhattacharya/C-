#include <iostream>
using namespace std;

class SectionB; // Forward declaration

class SectionA {
private:
    int marksA;
public:
    SectionA(int m) : marksA(m) {}
    friend float calculateAverage(SectionA, SectionB);
};

class SectionB {
private:
    int marksB;
public:
    SectionB(int m) : marksB(m) {}
    friend float calculateAverage(SectionA, SectionB);
};

float calculateAverage(SectionA a, SectionB b) {
    return (a.marksA + b.marksB) / 2.0;
}

int main() {
    SectionA sectionA(85);
    SectionB sectionB(90);
    cout << "Average Marks: " << calculateAverage(sectionA, sectionB) << endl;
    return 0;
}
