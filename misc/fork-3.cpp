#include <unistd.h>
#include <iostream>

static int data = 2;

int main()
{
  data = 3;
  auto id1 = fork();
  auto id2 = fork();
  auto id3 = fork();

  std::cout << "id1 : " << id1 << ", id2: " << id2 << ", id3: " << id3 << std::endl;
}
