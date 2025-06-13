#include <signal.h>
#include <unistd.h>
#include <iostream>


void handler(int sig)
{
  if (sig == SIGINT) {
    std::cout << "caught signal!" << std::endl;
  }
}

int main()
{
  signal(SIGINT, handler);

  for (auto i = 0; i < 10; i ++) {
    std::cout << "hello, world!\n";
    sleep(1);
  }
}
