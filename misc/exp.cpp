#include <iostream>
#include <exception>
void test(int i)
{
if (i == 42) {
throw 42;
}
}

int main(void) {
try {
test(1);
std::cout << "attempt #1: passed\n";
test(21);
std::cout << "attempt #2: passed\n";
}
catch(...) {
std::cout << "exception catch\n";
}
}
