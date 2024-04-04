#include <algorithm>

#include "random_snake.h"

using std::vector;

RandomSnake::RandomSnake(int grid_width, int grid_height) :
    Snake(grid_width, grid_height), gen(rd()), distrib(10, 20)
{
    // We set the head to a random position (this could be the same as the user snake
    // if the user is very unlucky in which case the game would end immediately upon beginning)
    std::uniform_int_distribution<> width_distrib(0, grid_width);
    std::uniform_int_distribution<> height_distrib(0, grid_height);
    head_x = width_distrib(gen);
    head_y = height_distrib(gen);
}

void RandomSnake::Update() {
    // The snake will randomly pick a direction and travel in that direction for between 10
    // and 20 frames (as controlled by the distrib initialization above)
    SDL_Point prev_cell;
    SDL_Point current_cell;
    if (travelling) {
        travelling_count--;
        if (travelling_count == 0)
            travelling = false;
        prev_cell = {
            static_cast<int>(head_x),
            static_cast<int>(head_y)};  // We first capture the head's cell before updating.
        UpdateHead();
        current_cell = {
            static_cast<int>(head_x),
            static_cast<int>(head_y)};  // Capture the head's cell after updating.
        
        // Update all of the body vector items if the snake head has moved to a new
        // cell.
        if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y)
            UpdateBody(current_cell, prev_cell);
        return;
    }
    travelling = true;
    travelling_count = distrib(gen);
    vector<Direction> newDirection;
    std::sample(directions.begin(), directions.end(), std::back_inserter(newDirection), 1, gen);
    Direction opposite;
    switch (direction) {
        case Direction::kDown:
            opposite = Direction::kUp;
            break;
        case Direction::kLeft:
            opposite = Direction::kRight;
            break;
        case Direction::kRight:
            opposite = Direction::kLeft;
            break;
        case Direction::kUp:
            opposite = Direction::kDown;
            break;
    }
    if (newDirection[0] != opposite or size == 1) {
        direction = newDirection[0];
    }
    prev_cell = {
        static_cast<int>(head_x),
        static_cast<int>(
            head_y)};  // We first capture the head's cell before updating.
    UpdateHead();
    current_cell = {
        static_cast<int>(head_x),
        static_cast<int>(head_y)};  // Capture the head's cell after updating.

    // Update all of the body vector items if the snake head has moved to a new
    // cell.
    if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
        UpdateBody(current_cell, prev_cell);
    }
}