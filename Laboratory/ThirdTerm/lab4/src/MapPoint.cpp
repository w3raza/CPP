#include "MapPoint.h"

#ifndef MapPoint_h
#define MapPoint_h
void MapPoint::print() const{
    const double longitude = getLongitude();
    const double latitude = getLatitude();

    std::cout << "Wspolrzedne dla " << getName()
    << ": " << abs(longitude)
    << (longitude > 0 ? 'E' : 'W')
    << ", " << abs(latitude)
    << (latitude > 0 ? 'N' : 'S')
    << std::endl;
}

void MapPoint::move(const double longitudeShift, const double latitudeShift){
    double longitude = getLongitude() + longitudeShift;
    double latitude = getLatitude() + latitudeShift;
    setPoint(getName(), longitude, latitude);
}

const double calculateDistance(const double x1, const double x2){
    if((x1 > 0 && x2 > 0) || (x1 < 0 && x2 < 0)){
        return x1 - x2;
    }else{
        return abs(x1) + abs(x2);
    }
}

const double distance(const MapPoint& obj1, const MapPoint& obj2){
    double longitude1 = obj1.getLongitude();
    double latitude1 = obj1.getLatitude();
    double longitude2 = obj2.getLongitude();
    double latitude2 = obj2.getLatitude();
    double delta_x = calculateDistance(longitude1, longitude2);
    double delta_y = calculateDistance(latitude1, latitude2);

    return sqrt(pow(delta_x, 2) + pow(delta_y, 2));
}

const MapPoint* closestPlace(const MapPoint& obj1, const MapPoint& obj2, const MapPoint& obj3){
    double closet = distance(obj1, obj2);

    if(closet > distance(obj1, obj3)){
        closet = distance(obj1, obj3);

        return (&obj3);
    }

    return (&obj2);
}

const double calculateMiddle(const double x1, const double x2){
    return (x1 + x2)/2;
}

const MapPoint inTheMiddle(const MapPoint* obj1, const MapPoint* obj2, const std::string& name){
    double longitude1 = obj1->getLongitude();
    double latitude1 = obj1->getLatitude();
    double longitude2 = obj2->getLongitude();
    double latitude2 = obj2->getLatitude();
    double x = calculateMiddle(longitude1, longitude2);
    double y = calculateMiddle(latitude1, latitude2);
    MapPoint mapPoint(name, x, y);

    return mapPoint;
}
#endif