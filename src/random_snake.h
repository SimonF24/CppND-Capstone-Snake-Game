#ifndef RANDOM_SNAKE_H
#define RANDOM_SNAKE_H

#include <random>
#include <vector>

#include "snake.h"

class RandomSnake : public Snake {
    public:
        RandomSnake(int grid_width, int grid_height);
        void Update() override;

    private:
        bool travelling = false;
        int travelling_count;
        std::random_device rd;
        std::mt19937 gen;
        std::vector<Direction> directions = {Direction::kDown, Direction::kLeft, Direction::kRight, Direction::kUp};
        std::uniform_int_distribution<> distrib;
};

#endif