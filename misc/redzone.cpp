__attribute__((noinline)) 
void demo_redzone() {
    volatile char buffer[120]; // 小于128字节
    buffer[0] = 'A';          // 使用红区存储
}

int main() {
    demo_redzone();
    return 0;
}
