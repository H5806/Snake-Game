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

    // ���� ����� ����
    Snake();

    // ���� ����� ����� �����
    Snake(Point start_position);

    // ����� ��� ����
    Point front() const;

    // �������� ����� ������ ����
    void move();
    void grow();
    void changeDirection(Direction new_direction);
};
