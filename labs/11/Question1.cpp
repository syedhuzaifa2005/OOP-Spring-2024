#include <iostream>
using namespace std;


class convert{
protected:
    float val1;
    float val2;

public:
    convert(float v1) : val1(v1) {}
    virtual void compute() = 0;
};

class l_to_g : public convert{
public:
    l_to_g(float v1) : convert(v1) {}
    void compute()
    {
        val2 = val1 / 3.78541;
        cout << val2 << " Gallons" << endl;
    }
};

class f_to_c : public convert{
public:
    f_to_c(float v1) : convert(v1) {}
    void compute()
    {
        val2 = (val1 - 32) * 5 / 9;
        cout << val2 << " Celcius" << endl;
    }
};
int main(){
    l_to_g litres(4);
    convert *c = &litres;
    c->compute();

    f_to_c farheniet(70);
    convert *c2 = &farheniet;
    c2->compute();

    return 0;
}
