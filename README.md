### Snake Game on STM32 DISCO F429ZI

[About](#about)

[Game Appereance](#game-appereance)

[Building the project](#building-the-project)

## About

Project is made with use of [SnakeCore](https://github.com/FilipZajdel/SnakeCore) and [mbed platform](https://github.com/ARMmbed/mbed-cli) for STM32. It uses touchscreen for controlling and displaying the game.

## Game appereance

![](images/game.jpg)
*image1. Game appereance*



## Building the project

Project is built with mbed-cli. It was built  following tools:
* Ubuntu 18.04 LTS
* mbed-cli 1.10.0
* Python 2.7.15rc1
* gcc-arm-eabi-8-2018-q4

In order to build the project use following steps:

```shell
git clone --recursive https://github.com/FilipZajdel/StmSnake
cd StmSnake/
mbed new .
mbed deploy
mbed compile -t GCC_ARM -m DISCO_F429ZI
```

1. Important: Project is written using C++14, in order to change compiler standard to c++14, modify files in following directory: StmSnake/mbed-/tools/profiles . You should find develop.json, debug.json and release.json. Find "cxx" key and modify its value from "-std=gnu++98" to "-std=gnu++14"

2. Important: Probably it will be necessary to comment/remove one line in SnakeCore. Don't care if project compiles. Otherwise comment line indicated by compiler (line containing srand(time(NULL))).
