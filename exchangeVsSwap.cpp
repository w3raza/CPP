#include <utility>
#include <iostream>

int main()
{

    int x = 2;
    int x2 = 1;
    auto y = std::exchange(x, 4);
    // auto y = std::exchange(x, x2); OK!
    // y == 2;
    // x == 4;
    // 4...? anything

    std::swap(x, x2);
    //  std::swap(x, 2); // NOT!
    // x == 1;
    // x2 == 4;
}