cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 17)

project(BlackJackGame)

include_directories(../blackjack)

add_executable(${PROJECT_NAME} tests/main.cpp blackjack/blackjack.cpp blackjack/cards.cpp blackjack/console.cpp blackjack/player.cpp)

