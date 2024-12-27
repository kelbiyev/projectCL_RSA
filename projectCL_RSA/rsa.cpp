#include "rsa.h"
#include <iostream>

bool IsDigitSimple(cpp_int n) {
    if (n <= 1) return false;
    for (cpp_int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

cpp_int ModulStepen(cpp_int base, cpp_int exp, cpp_int mod) {
    cpp_int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

cpp_int KeyGen(cpp_int p, cpp_int q) {
    if (!IsDigitSimple(p) || !IsDigitSimple(q)) {
        std::cout << "error: p and q might be simple digits" << std::endl;
        return cpp_int(0);
    }
    cpp_int phi = (p - 1) * (q - 1);
    cpp_int e = 65537;
    cpp_int d = 0;
    cpp_int k = 1;
    while (true) {
        cpp_int val = k * phi + 1;
        if (val % e == 0) {
            d = val / e;
            break;
        }
        ++k;
    }
    return d;
}

cpp_int TextToNum(const std::string &text) {
    cpp_int num = 0;
    for (char c : text) {
        num = num * 256 + static_cast<unsigned char>(c);
    }
    return num;
}

std::string NumToText(cpp_int num) {
    std::string text;
    while (num > 0) {
        text.insert(text.begin(), static_cast<char>(num % 256));
        num /= 256;
    }
    return text;
}

cpp_int EncBlock(cpp_int m, cpp_int e, cpp_int n) {
    return ModulStepen(m, e, n);
}

cpp_int DecBlock(cpp_int c, cpp_int d, cpp_int n) {
    return ModulStepen(c, d, n);
}

std::vector<cpp_int> EncText(const std::string &message, cpp_int e, cpp_int n, cpp_int s) {
    std::vector<cpp_int> encBlocks;
    size_t blockSize = s.convert_to<size_t>();
    for (size_t i = 0; i < message.size(); i += blockSize) {
        std::string block = message.substr(i, blockSize);
        cpp_int m = TextToNum(block);
        encBlocks.push_back(EncryptBlock(m, e, n));
    }
    return encBlocks;
}


std::string DecText(const std::vector<cpp_int> &encBlocks, cpp_int d, cpp_int n) {
    std::string decMessage;
    for (const cpp_int &block : encBlocks) {
        cpp_int decBlock = DecBlock(block, d, n);
        decMessage += NumToText(decBlock);
    }
    return decMessage;
}