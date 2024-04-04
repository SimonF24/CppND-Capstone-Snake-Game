#include <future>
#include <iostream>

#include "game.h"
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      random_snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, random_snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  std::future<void> snake_ftr = std::async(&Snake::Update, &snake);
  std::future<void> random_snake_ftr = std::async(&RandomSnake::Update, &random_snake);

  snake_ftr.wait();
  random_snake_ftr.wait();

  // We also check for a collision between the snakes
  SDL_Point random_snake_head = {static_cast<int>(random_snake.head_x),
    static_cast<int>(random_snake.head_y)};
  SDL_Point snake_head = {static_cast<int>(snake.head_x),
    static_cast<int>(snake.head_y)};
  if (random_snake_head.x == snake_head.x and random_snake_head.y == snake_head.y)
    snake.alive = false;
  for (SDL_Point const &item : snake.body) {
    if (random_snake_head.x == item.x and random_snake_head.y == item.y)
      snake.alive = false;
  }
  for (SDL_Point const &item : random_snake.body) {
    if (snake_head.x == item.x and snake_head.y == item.y)
      snake.alive = false;
  }

  // Check if there's food over here
  if (food.x == static_cast<int>(snake.head_x) && food.y == static_cast<int>(snake.head_y)) {
    score++;
    PlaceFood();
    // Grow snake and increase speed of the user's snake and the random snake.
    snake.GrowBody();
    snake.speed += 0.02;
    random_snake.speed += 0.02;
  } else if (food.x == static_cast<int>(random_snake.head_x) && food.y == static_cast<int>(random_snake.head_y)) {
    PlaceFood();
    // Grow snake and increase speed.
    random_snake.GrowBody();
    random_snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }