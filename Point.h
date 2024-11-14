#pragma once

class Point {
public:
    int x, y;

    // בנאי ברירת מחדל
    Point() : x(0), y(0) {}

    // בנאי שמקבל קואורדינטות X ו-Y
    Point(int x, int y) : x(x), y(y) {}

    // השוואה בין נקודות
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }
};
