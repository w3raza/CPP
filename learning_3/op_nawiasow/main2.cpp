#include <iostream>
#include <functional> //std::function
#include <vector>     //std::vector dynamiczna tablica, do każdego jej elementu oraz możemy w każdym momencie zwiększać jej wielkość

struct F1
{
    void operator()(int n)
    {
        std::cout << __PRETTY_FUNCTION__ << ": " << n << std::endl;
    }
};

struct F2
{
    void operator()(int n)
    {
        std::cout << __PRETTY_FUNCTION__ << ": " << n << std::endl;
    }
};

struct F3
{
    void operator()(int n)
    {
        std::cout << __PRETTY_FUNCTION__ << ": " << n << std::endl;
    }
};

struct F4
{
    void operator()()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

struct F5
{
    void operator()()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

/////////////////////////////////////////////////////////
int main()
{

    std::vector<std::function<void(int)>> vec;
    std::vector<std::function<void()>> vec2;

    vec.emplace_back(F1()); //Appends a new element to the end of the container.
    vec.emplace_back(F2());
    vec.emplace_back(F3());

    int i = 0;
    for (auto &el : vec)
    {
        el(++i);
        vec2.emplace_back(std::bind(el, i)); //std::bind
    }

    vec2.push_back(F4());
    vec2.emplace_back(F5());
    for (auto &el : vec2)
        el();
}
