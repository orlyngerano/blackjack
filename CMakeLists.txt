cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 17)

project(BlackJackGame)

set(INCLUDE_DIRS ${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME} tests/main.cpp blackjack/blackjack.cpp blackjack/cards.cpp blackjack/console.cpp blackjack/player.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})
