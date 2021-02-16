#include "console.hpp"
#include <iostream>
#include <string>

int
main(int argc, const char* argv[])
{
  std::string playerName = "Anonymous";

  if (argc > 1 && argv[1][0] != '\0') {
    playerName = argv[1];
  }

  Console console(playerName);
  console.play();

  return 0;
}