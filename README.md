> [!NOTE]  
> Readme written by GitHub Copilot

# Bolatron Raylib C++

A simple shooter game built using Raylib and C++.

## Introduction

Bolatron Raylib C++ is a straightforward shooter game that leverages the Raylib library for graphics and audio. The game involves controlling a ball that can shoot bullets and avoid enemies.

## Features

- Control a ball using keyboard inputs.
- Shoot bullets towards the mouse pointer.
- Enemies spawn randomly and move towards the player.
- Collision detection between bullets and enemies, as well as between the player and enemies.
- Background music and sound effects for shooting and reloading.

## Demo video

https://github.com/user-attachments/assets/5cdb139e-bde7-4b28-811b-d7856d6cd668

## Installation

### Prerequisites

- CMake 3.10 or higher
- Raylib library

### Building the Project

1. Clone the repository:
   ```sh
   git clone https://github.com/AntonioRodriguezRuiz/bolatron-raylib-cpp.git
   cd bolatron-raylib-cpp
   ```

2. Create a build directory and navigate to it:
   ```sh
   mkdir build
   cd build
   ```

3. Run CMake to configure the project:
   ```sh
   cmake ..
   ```

4. Build the project:
   ```sh
   make
   ```

## Usage

1. Navigate to the build directory:
   ```sh
   cd build
   ```

2. Run the game executable:
   ```sh
   ./game
   ```

## Game Controls

- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right
- **Mouse Left Button**: Shoot
- **Mouse Right Button**: Reload

## Code Structure

- `CMakeLists.txt`: CMake configuration file for building the project.
- `src/main.cpp`: Entry point of the game.
- `src/character/ball.cpp` and `src/character/ball.h`: Implementation and definition of the Ball class.
- `src/enemies/enemy.cpp` and `src/enemies/enemy.h`: Implementation and definition of the Enemy class.
- `src/scene/scene.cpp` and `src/scene/scene.h`: Implementation and definition of the Scene class.

## Contributing

Contributions are welcome! Please fork the repository and create a pull request with your changes.

## License

This project is licensed under the MIT License.
