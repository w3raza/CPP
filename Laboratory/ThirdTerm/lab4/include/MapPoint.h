#pragma once
#include<iostream>
#include<math.h>
#include<string>

class MapPoint{
    public:
    MapPoint(): _longitude(0), _latitude(0), _name("") {};
    MapPoint(const std::string &name, const double longitude, const double latitude): _longitude(longitude), _latitude(latitude), _name(name){}
    void setPoint(const std::string &name, const double longitude, const double latitude) const;
    void print() const;
    const double getLongitude() const;
    const double getLatitude() const;
    const std::string getName() const;
    void move(const double longitudeShift, const double latitudeShift);

    private:
    mutable double _longitude;
    mutable double _latitude;
    mutable std::string _name;
};

const double distance(const MapPoint& obj1, const MapPoint& obj2);
const MapPoint* closestPlace(const MapPoint& obj1, const MapPoint& obj2, const MapPoint& obj3); 
const MapPoint inTheMiddle(const MapPoint* obj1, const MapPoint* obj2, const std::string& name);

inline void MapPoint::setPoint(const std::string &name, const double longitude, const double latitude) const{
    _longitude = longitude;
    _latitude = latitude;
    _name = name;
}

inline const double MapPoint::getLongitude() const{
    return _longitude;
}

inline const double MapPoint::getLatitude() const{
    return _latitude;
}

inline const std::string MapPoint::getName() const{
    return _name;
}