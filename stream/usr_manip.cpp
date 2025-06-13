#include <iostream>
#include <iomanip>

namespace usr {
  class hex_t {} hex;
};

std::ostream&
operator<<(std::ostream& os, const usr::hex_t& obj) {
  os << std::hex << std::showbase << std::internal
     << std::setfill('0') << std::setw(28);
  return os;
}


int main()
{
  std::cout << usr::hex << 51 << '\n';
}
