#include <iomanip>
#include <iostream>

int main()
{
  std::cout << "the width is 18 " << std::setw(18) << std::setfill('-') << 51 << '\n';
  std::cout << "the width is 18 " << std::setw(18) << std::setfill('*') << 515151515151 << '\n';
}
