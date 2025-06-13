#define GSL_THROW_ON_CONTRACT_VIOLATION
#include <gsl/gsl>
#include <iostream>

int main(void)
{
uint64_t val = 0xFFFFFFFFFFFFFFFF;
try {
gsl::narrow<uint32_t>(val);
}
catch(...) {
std::cout << "narrow failed\n";
}
}
