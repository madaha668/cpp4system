#define concat1(a,b) a ## b
#define concat2(a,b) concat1(a,b)
#define ___ concat2(dont_care, __COUNTER__)
#include <gsl/gsl>
#include <iostream>
int main(void)
{
auto ___ = gsl::finally([]{
std::cout << "Hello World\n";
});
}
