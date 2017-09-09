#include <cstdio>
#include <cstdint>
#include <vector>

unsigned int GetTLBHash(unsigned addr)
{
    uint64_t wider = static_cast<uint64_t>(addr) | 0xA00000000;

    uint64_t result = wider & 0b111111;
    for (int i = 0 ; i < 5; i++)
    {
        wider >>= 6;
        result ^= (wider & 0b111111);
    }

    return (unsigned int)result;
}

int main()
{
    std::vector<int> freq;
    freq.resize(64);

    for (unsigned int i = 0; i < 10000; i+=31)
    {
        freq[GetTLBHash(i)]++;
    }

    for (size_t j = 0; j < 64; j++)
    {
        printf("%u\n", freq[j]);
    }

    return 0;
}