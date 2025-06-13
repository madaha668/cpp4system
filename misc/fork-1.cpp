#include <unistd.h>
#include <iostream>

static int data = 2;

int main()
{
  data = 3;
  if (fork() != 0) {
    data = 51;
  }
  std::cout << "the data is " << data << std::endl;
}
