#pragma once

#include <vector>
#include <iostream>

enum Nukleotyp { A, C, T, G, U };

class RNA{
    public:
        RNA() = default;

        RNA(const std::vector<Nukleotyp>& seq): _sequence(seq){}

        RNA(const RNA& other) : _sequence(other._sequence) {}

        RNA(RNA&& other) noexcept : _sequence(std::move(other._sequence)) {}

        RNA& operator=(const RNA& other) {
            if (this != &other) {
                _sequence = other._sequence;
            }
            return *this;
        }

        RNA& operator=(RNA&& other) noexcept {
            if (this != &other) {
                _sequence = std::move(other._sequence);
            }
            return *this;
        }

        std::vector<Nukleotyp> getSequence() const{
            return _sequence;
        }

        RNA* get_RNA(){
            return this;
        }

        RNA& mutate(){
            _sequence.push_back(_sequence.front());
            _sequence.erase(_sequence.begin());

            return *this;
        }

    private:
        std::vector<Nukleotyp> _sequence;
};

std::ostream& operator<<(std::ostream& os, const RNA& rna){
    for(const auto& n : rna.getSequence()){
        switch (n) {
                case A:
                    os << 'A' << " ";
                    break;
                case C:
                    os << 'C' << " ";
                    break;
                case T:
                    os << 'T' << " ";
                    break;
                case G:
                    os << 'G' << " ";
                    break;
                case U:
                    os << 'U' << " ";
            }
    }

    return os << std::endl;
}