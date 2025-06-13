#include <gsl/gsl>
gsl::not_null<int *>
test(gsl::not_null<int *> p)
{
return p;
}

int main(void) {
auto p1 = std::make_unique<int>();
p1 = nullptr;
auto p2 = test(gsl::not_null(p1.get()));
}
