#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

static int data = 2;

int main()
{
  data = 3;
  auto id1 = fork();

  if (id1 != 0) {
    wait(nullptr);
    std::cout << "parent" << std::endl;
  } else 
    std::cout << "child" << std::endl;
}
