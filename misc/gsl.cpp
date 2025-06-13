#include <gsl/gsl>
void init(int *p)
{
*p = 0;
}

int main(void) {
gsl::owner<int *> p = new int;
init(p);
delete p;
}
