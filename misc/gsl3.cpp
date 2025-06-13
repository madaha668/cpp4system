#define GSL_THROW_ON_CONTRACT_VIOLATION
#include <gsl/gsl>
#include <iostream>

int main(void)
{
  try {
    Expects(false);
  } catch (const gsl::fail_fast &e) {
    std::cout << "exception: " << e.what() << '\n';
  }
}
