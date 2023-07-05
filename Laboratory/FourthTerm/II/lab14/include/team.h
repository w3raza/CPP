#ifndef TEAM_H
#define TEAM_H

#pragma once
#include <iostream>
#include <vector>
#include "member.h"

class Team
{
private:
    std::vector<Member> _vec;
public:
    void add(Member& member){
        if(std::find(_vec.begin(), _vec.end(), member) == _vec.end()){
            _vec.push_back(member);
        }
    }

    Team& operator+(Team& other) {
        std::for_each(other._vec.begin(), other._vec.end(), [this](Member& member) { add(member); });

        return *this;
    }

    void sort(){
        std::sort(_vec.begin(), _vec.end());
    }

    void kill(std::function<bool(const Member&)> pred){
        _vec.erase(std::remove_if(_vec.begin(), _vec.end(), pred), _vec.end());
    }

    friend std::ostream& operator<<(std::ostream& os, Team& team){
        team.sort();
        std::for_each(team._vec.begin(), team._vec.end(), [](const Member& member){member.print();});

        return os;
    }
};


#endif