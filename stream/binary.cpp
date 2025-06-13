#include <iostream>
#include <bitset>
#include <climits>
#include <cstring>
#include <type_traits>

template <typename T>
void print_binary(T value) {
    constexpr std::size_t num_bits = sizeof(T) * CHAR_BIT;
    
    // 处理整数和浮点数的位表示
    using UIntType = 
        std::conditional_t<sizeof(T) <= sizeof(uint64_t), uint64_t, 
        std::conditional_t<sizeof(T) <= sizeof(uintmax_t), uintmax_t, void>>;
    
    static_assert(!std::is_same_v<UIntType, void>, "Unsupported type size");
    
    UIntType bits = 0;
    std::memcpy(&bits, &value, sizeof(T)); // 安全拷贝位模式
    
    std::bitset<num_bits> bs(bits);
    std::cout << bs << '\n';
}

int main() {
    // 测试整数
    int a = 42;
    print_binary(a); // 00101010 (完整32位)
    
    // 测试浮点数
    float b = 3.14f;
    print_binary(b); // IEEE 754 表示
    
    // 测试大端序兼容性
    uint16_t c = 0xABCD;
    print_binary(c); // 1010101111001101
}
