#ifndef RSA_H
#define RSA_H

#include <boost/multiprecision/cpp_int.hpp>
#include <vector>
#include <string>

using namespace boost::multiprecision;

bool IsDigitSimple(cpp_int n);
cpp_int ModulStepen(cpp_int base, cpp_int exp, cpp_int mod);
cpp_int KeyGen(cpp_int p, cpp_int q);
cpp_int TextToNum(const std::string &text);
std::string NumToText(cpp_int num);
cpp_int EncBlock(cpp_int m, cpp_int e, cpp_int n);
cpp_int DecBlock(cpp_int c, cpp_int d, cpp_int n);
std::vector<cpp_int> EncText(const std::string &message, cpp_int e, cpp_int n,cpp_int s);
std::string DecText(const std::vector<cpp_int> &encBlocks, cpp_int d, cpp_int n);

#endif // RSA_H