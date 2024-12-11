#include "Snake.h"

Snake::Snake() : current_direction(RIGHT) {
    body.push_back(Point(5, 5)); // ראש הנחש בנקודת התחלה
}

Snake::Snake(Point start_position) : current_direction(RIGHT) {
    body.push_back(start_position);
}

Point Snake::front() const {
    return body.front(); // מחזיר את מיקום הראש
}

void Snake::move() {
    Point head = front();
    // תזוזת הראש לפי הכיוון הנוכחי
    switch (current_direction) { 
    case UP:    head.y -= 1; break;
    case DOWN:  head.y += 1; break;
    case LEFT:  head.x -= 1; break;
    case RIGHT: head.x += 1; break;
    }

    // הוספת ראש חדש והסרת זנב
    body.insert(body.begin(), head);
    body.pop_back();
}

void Snake::grow() {
    Point head = front();
    switch (current_direction) {
    case UP:    head.y -= 1; break;
    case DOWN:  head.y += 1; break;
    case LEFT:  head.x -= 1; break;
    case RIGHT: head.x += 1; break;
    }
    body.insert(body.begin(), head); // הוספת ראש חדש מבלי להסיר את הזנב
}

void Snake::changeDirection(Direction new_direction) {
    // מניעת תנועה בכיוון הפוך
    if ((current_direction == UP && new_direction != DOWN) ||
        (current_direction == DOWN && new_direction != UP) ||
        (current_direction == LEFT && new_direction != RIGHT) ||
        (current_direction == RIGHT && new_direction != LEFT)) {
        current_direction = new_direction;
    }
}
