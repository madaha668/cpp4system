#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

static int data = 2;

int main()
{
  data = 3;
  auto id1 = fork();
  if (id1 == 0)
      std::cout << "fork id1: (mypid: " << getpid() << ", parent pid: " << getppid() <<  ")" << std::endl;

  auto id2 = fork();
  if (id2 == 0)
      std::cout << "fork id2: (mypid: " << getpid() << ", parent pid: " << getppid() <<  ")" <<  std::endl;
  auto id3 = fork();
  if (id3 == 0)
      std::cout << "fork id3: (mypid: " << getpid() << ", parent pid: " << getppid() <<  ")" <<  std::endl;

  sleep(1);
  while (1) {
    auto id = wait(nullptr);
    if (id == -1)
      break;

    if (id == id1) 
      std::cout << "child#1 exits with id1: " << id1 <<  std::endl;
    if (id == id2) 
      std::cout << "child#2 exits with id2: " << id2 <<  std::endl;
    if (id == id3) 
      std::cout << "child#3 exits with id3: " << id3 <<  std::endl;
  }
}
