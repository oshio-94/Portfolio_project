# The Maze Portfolio Project

The Maze Project is a simple 3D game that handles keyboard/mouse input in order to move and control the players. Its meant to be a fun and interactive game which I developed in order to learn a new language, showcase my skill and to also have fun while doing so.

## Technology
* C++ was used as the core programming language to handle all the core functions.
* SDL was used in order to generate the window, lectures and also handle user input (keyboard, mouse, audio).
* Raycasting was used in order to render a 3D perspective from the 2D map.

## Installation
```sh
$ git clone https://github.com/oshio-94/Portfolio_project.git
```
## Usage
### Keyboard Controls
* w for moving up                    
* d for moving right
* a for moving left                  
* s for moving down

## Compilation
```sh
$ gcc -Wall -Werror -Wextra main.cpp -w -lSDL2 -o main;
```
## Files
All the following files are written in C++

## Screenshots
![The Maze Demo Screenshot](link)

| Filename | Description |
| -------- | ----------- |
| `KeyboardController.h` | `For handling the user inputs` |
| `textureManager.h` | `For handling the uploading and managing of textures` |
| `GameObject.h` | `For handling the Game object rendering` |
| `test_maze_0.h` | `Contains most logical functions` |
| `Vector2D.h` | `Movement of Sprite` |
| `SpriteComponent.h` | `For handling the player avatar` |
| `Map.h` | `For building the 2D Map` |
| `main.cpp` | `The main C++ file` |
| `assets` | `Picture and Textures` |
| `ECS.h` | `Handling the Entity Component Systems` |
| `` | `` |
| `` | `` |
| `` | `` |