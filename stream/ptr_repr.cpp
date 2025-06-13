#include <iostream>

int main()
{
  int i = 0xdeadbeef;

  std::cout << &i << '\n';
  std::cout << std::hex << std::showbase << std::uppercase << reinterpret_cast<uintptr_t>(&i) << '\n';
}
