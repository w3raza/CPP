#include <set>
#include <string>
#include <iostream>
#include <iterator>

class Person {
public:
    Person(std::string lastName, std::string firstName)
        : m_lastName(std::move(lastName)), m_firstName(std::move(firstName)) {}

    const std::string& lastName() const { return m_lastName; }
    const std::string& firstName() const { return m_firstName; }

private:
    std::string m_lastName;
    std::string m_firstName;
};

// operator porównujący do sortowania
bool operator<(const Person& a, const Person& b) {
    if (a.lastName() != b.lastName()) {
        return a.lastName() < b.lastName();
    } else {
        return a.firstName() < b.firstName();
    }
}

// operator wyjścia do drukowania
std::ostream& operator<<(std::ostream& os, const Person& p) {
    return os << p.lastName() << " " << p.firstName();
}

// typedef dla kontenera
typedef std::set<Person> Container;

int main ()
{
    typedef Container kontener_typ;
    kontener_typ c;
    c.insert(Person("Nowak","Jan"));
    c.insert(Person("Nowak","Adam"));
    c.insert(Person("Kowalski","Jan"));
    c.insert(Person("Nowak","Adam"));
    c.insert(Person("Iksinski","Adam"));
    std::copy (c.begin(), c.end(), std::ostream_iterator<Person>(std::cout, ", "));
    return 0;
}
// Wynika działania:
// Iksinski Adam, Kowalski Jan, Nowak Adam, Nowak Jan,

// /* UZUPEŁNIĆ */
// int main ()
// {
// typedef /* UZUPEŁNIĆ */ kontener_typ;
// kontener_typ c;
// c.insert(Person("Nowak","Jan"));
// c.insert(Person("Nowak","Adam"));
// c.insert(Person("Kowalski","Jan"));
// c.insert(Person("Nowak","Adam"));
// c.insert(Person("Iksinski","Adam"));
// std::copy (c.begin(), c.end(), /*UZUPEŁNIĆ*/);
// }
// Wynika działania:
// Iksinski Adam, Kowalski Jan, Nowak Adam, Nowak Jan,