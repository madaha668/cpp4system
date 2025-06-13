#include <signal.h>
#include <unistd.h>
#include <iostream>


static volatile int loop = 1;

void handler(int sig)
{
  if (sig == SIGINT) {
    std::cout << "caught signal!" << std::endl;
    loop = 0;
  }
}

int main()
{
  signal(SIGINT, handler);

  for (auto i = 0; i < 10; i ++) {
    std::cout << "hello, world!\n";
    sleep(1);
    if (loop == 0)
      break;
  }
}
