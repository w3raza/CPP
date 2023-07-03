#include <iostream>
#include <stdexcept>

class Fraction
{
public:
    Fraction(int l = 0, int m = 1) noexcept : _l(l), _m(m)
    {
        if (m == 0)
            throw std::runtime_error("invalid");
    }

private:
    int _l = 0;
    int _m = 1;
};

int main()
{
    try
    {
        Fraction f(1, 0);
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what() << '\n';
    }
}
//terminate called after throwing an instance of 'std::runtime_error'
//  what():  invalid
// Aborted