# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## New Features

This version features several new features compared to the original including a second snake that moves randomly, a
score leaderboard, and the ability to control the initial speed the snakes move at. You must avoid the snake moving randomly,
if it touches you or you touch it, the game is over. The score leaderboard is accessible as a scores.txt file and shows 
the top 10 scores achieved. To control the initial speed of the game you can change a speed.txt file to be any value you would like.

## Rubric Points Addressed

# Loops, Functions, I/O

This program demonstrates an understanding of C++ functions and control structures (throughout).

This program reads and writes to an external file as part of its necessary operation (scores.cpp, snake.cpp lines 6-18).

This program accepts user input and processes the input (input from files - scores.cpp, snake.cpp lines 6-18)

This program uses data structures and immutable variables (throughout, e.g. scores.cpp).

# Object Oriented Programming

One or more classes are added to the project with appropriate access specifiers for class members (random_snake.h, scores.h)

Class constructors utilize member initialization lists (snake.cpp lines 6-18, random_snake.cpp lines 7-16)

Classes abstract implementation details from their interfaces (snake.h, random_snake.h, scores.h)

Classes follow an appropriate inheritance hierarchy with virtual and override functions (snake.h, random_snake.h)

# Memory Management

The project makes use of references in function declarations (snake.h line 29, game.h line 14, controller.h lines 8 and 11, renderer.h line 16)

The project uses score / Resource Aquisition is Initialization (RAII) where appropriate (scores.h)

The project uses smart pointers instead of raw pointers (scores.h line 17)

# Concurrency

The project uses multithreading (game.cpp lines 74-78)

A promise and future is used in the project (game.cpp lines 74-78)

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
