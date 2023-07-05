#ifndef FUNLAMBDA_H
#define FUNLAMBDA_H

#include <vector>
#include <iostream>
#include <functional>

namespace flmbd{
    double approximateDerivative(std::function<double(double)> fun, const double& x, const double& h){
        return (fun(x+h)-fun(x-h))/(2*h);
    }

    template<typename T>
    struct Sum{
        T& _sum;
        Sum(T& s) : _sum(s){}

        void operator()(T& val){
            _sum += val;
        }
    };

    // template<typename Iterable, typename Predicate>
    // void filter(Iterable iterable, Predicate predicate){
    //     for(auto& el : iterable){
    //         if(predicate(el)){
    //             std::cout << el << " ";
    //         }
    //     }
    //     std::cout << std::endl;
    // }

    template<typename Iterable, typename Predicate>
    struct filter{
        filter(Iterable iterable, Predicate predicate): iterable_(iterable), predicate_(predicate){
            for(auto& el : iterable_){
                if(predicate_(el)){
                    std::cout << el << " ";
                }
            }
            std::cout << std::endl;
        }

    private:
        Iterable iterable_;
        Predicate predicate_;
    };

    template<typename T>
    bool even(T x){
        return !(x % 2);
    }

    template<typename T>
    bool odd(T x){
        return (x % 2);
    }

    template<typename T>
    struct GreaterThan{
        T _val;

        GreaterThan(const T& val): _val(val){}

        bool operator()(const T& x){
            return x > _val;
        }
    };
}

#endif