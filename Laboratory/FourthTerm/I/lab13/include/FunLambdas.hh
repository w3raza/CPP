#include <vector>
#include <functional>

namespace flcpp{
    double approximateDerivative(std::function<double(double)> fun, double x, double h){
        return (fun (x+h) - fun(x-h)) / (2 * h);
    }

    template<typename T = int>
    class Sum{
    private:
        T& _s;
    public:
        Sum(T& s): _s(s){}
        void operator()(T val){
            _s += val;
        }
    };

    template<typename T, typename Predicate>
    void filter(const std::vector<T>& values, Predicate predicate){
        for(auto& el: values){
            if(predicate(el)){
                std::cout << el << " ";
            }
        }
        std::cout << std::endl;
    }

    template<typename T>
    std::function<bool(T)> even = [] (T val){
        return val % 2 == 0;
    };

    template<typename T>
    std::function<bool(T)> odd = [] (T val){
        return val % 2 == 1;
    };

    template<typename T>
    class GreaterThan{
    private:
        T _val;
    public:
        GreaterThan(T val): _val(val){}
        bool operator()(T val){
            return val > _val;
        }
    };
}