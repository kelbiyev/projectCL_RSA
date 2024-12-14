#ifndef rsa_h
#define rsa_h

#include <deque>
#include <iostream>
#include <algorithm>

typedef short int shint;

std::deque<shint> sh_input();

void sh_print(const std::deque<shint> &v);

std::deque<shint> sh_mp(const std::deque<shint> &first, const std::deque<shint> &second);

bool sh_gcd(const std::deque<shint> &first, int e);

int sh_mod_int(std::deque<shint> first, int e);
int sh_evklid(int a, int b);

std::deque<shint> sh_pow(const std::deque<shint> &first, int exp, const std::deque<shint> &n);
std::deque<shint> sh_mod(std::deque<shint> first, std::deque<shint> second);

std::pair<std::deque<shint>, std::deque<shint>> sh_divide(const std::deque<shint> &first, const std::deque<shint> &second);

bool sh_compare(const std::deque<shint> &first, const std::deque<shint> &second);

void sh_subtract(std::deque<shint> &first, const std::deque<shint> &second);
//--------------------------------------------------------------------
std::deque<shint> sh_division_int(std::deque<shint> first, int e);
std::deque<shint> sh_pow_deque(const std::deque<shint> &first, std::deque<shint> d, const std::deque<shint> &n);

bool sh_equal(const std::deque<shint> &first, const std::deque<shint> &second);

std::deque<char> sh_input_char();

std::pair<std::deque<shint>, std::deque<shint>> sh_encryption_char(const std::deque<char> &message, int e, const std::deque<shint> &n);

std::deque<shint> sh_decryption_char(std::pair<std::deque<shint>, std::deque<shint>> &cmessage, std::deque<shint> &d, const std::deque<shint> &n);
//---------------------------------------------------------------------
std::deque<shint> sh_calculation_d(const std::deque<shint> &phi, int e);
std::deque<shint> &operator ++(std::deque<shint> &first);

#endif //rsa_h
