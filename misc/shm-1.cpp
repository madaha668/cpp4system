#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <iostream>


char* get_shared_mem()
{
  auto key = ftok("myfile", 42);
  auto shm = shmget(key, 0x1000, 0666 | IPC_CREAT);

  return static_cast<char*>(shmat(shm, nullptr, 0));
}

int main()
{
  if (fork() != 0) {
    auto msg = get_shared_mem();
    msg[0] = 'A';
    wait(nullptr);
  } else {
    auto msg = get_shared_mem();
    while (msg[0] != 'A');
    std::cout << "child got " << msg[0] << std::endl;
  }
}
