#include <type_traits> // Dla std::is_pod i std::integral_constant
#include <deque>
#include <vector>
#include <iostream>

struct A
{
};
struct A_
{
    virtual ~A_() {}
};

template <
    bool boolean>
struct ForPOD
{
};

template <>
struct ForPOD<true>
{
    template <
        typename IterI,
        typename IterO>
    static void copy(IterI start, IterI end, IterO startO)
    {
        std::cout << "POD!" << std::endl;
    }
};

template <>
struct ForPOD<false>
{
    template <
        typename IterI,
        typename IterO>
    static void copy(IterI start, IterI end, IterO startO)
    {
        std::cout << "Non POD!" << std::endl;
    }
};

template <typename IterI, typename IterO>
void my_copy(IterI start, IterI end, IterO startO)
{
    ForPOD<std::is_pod<typename IterI::value_type>::value>::copy(start, end, startO);
}

int main()
{
    // prosze wykorzystac te informacje
    std::integral_constant<bool, true> tA = std::is_pod<A>::type();
    std::integral_constant<bool, false> tA_ = std::is_pod<A_>::type();

    // Iterator dla każdego kontenera ma zdefiniowany
    // typ value_type określający typ obiektu na który wskazuje
    std::deque<A> vA1;
    std::vector<A> vA2;
    my_copy(vA1.begin(), vA1.end(), vA2.begin());

    std::vector<A_> vA_1;
    std::deque<A_> vA_2;
    my_copy(vA_1.begin(), vA_1.end(), vA_2.begin());
}
/* output/wyjscie
Copying POD objects
Copying non-POD objects
*/
