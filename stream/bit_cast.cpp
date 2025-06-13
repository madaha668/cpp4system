#include <iostream>
#include <bitset>
#include <bit>      // std::bit_cast

int main() {
    float f = -123.45f;
    uint32_t raw = std::bit_cast<uint32_t>(f);
    std::bitset<32> bits(raw);

    std::cout << "Binary representation: " << bits << std::endl;
    return 0;
}
