#pragma once
#include <vector>
#include "Point.h"

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {
public:
    std::vector<Point> body;
    Direction current_direction;

    // בנאי ברירת מחדל
    Snake();

    // בנאי שמקבל נקודת התחלה
    Snake(Point start_position);

    // החזרת ראש הנחש
    Point front() const;

    // פונקציות תנועה וגידול הנחש
    void move();
    void grow();
    void changeDirection(Direction new_direction);
};
