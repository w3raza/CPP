#include<istream>
#include<string>

class Named{
    public:
    Named(): _name("None"){}
    Named(std::string name): _name(name){}
    std::string Name() const;
    friend void operator>>(std::string name, Named& named);

    private:
    std::string _name;
};

inline std::string Named::Name() const{
    return _name;
}

void operator>>(std::string name, Named& named)
{
    named._name = name;
}