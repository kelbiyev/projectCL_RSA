#include "rsa.h"
#include <iostream>

int main() {
    cpp_int p = 2305843009213693951;
    cpp_int q = 18014398241046527;

    cpp_int d = GenerateKey(p, q);
    cpp_int e = 65537;
    cpp_int n = p * q;
    cpp_int s = 0;

    std::string message = "12345678";
    s = message.length();
    std::cout<<s<<"\n";
    std::cout<<"Original message: "<<message<<"\n";

    std::vector<cpp_int> encMessage = EncText(message, e, n, s);
    std::cout<<"Encrypted message: ";
    for (const auto &block : encMessage) {
        std::cout<<block << " ";
    }
    std::cout<<std::endl;


    std::string decMessage = DecText(encMessage, d, n);
    std::cout<<"Decrypted message: "<<decMessage<<"\n";

    return 0;
}