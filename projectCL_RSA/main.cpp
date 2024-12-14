#include "rsa.h"

int main()
{
    std::deque<shint> p;
    std::deque<shint> q;

    std::cout << "p: \t";
    p = sh_input();
    std::cout << "q: \t";
    q = sh_input();

    std::deque<shint> n;

    n = sh_mp(p, q);
   
    std::cout << "n: \t";
    sh_print(n);

    p[0] -= 1;
    q[0] -= 1;

    std::cout << "p - 1\t";
    sh_print(p);

    std::cout << "q - 1\t";
    sh_print(q);

    std::deque<shint> phi;

    phi = sh_mp(p, q);

    std::cout << "phi\t";
    sh_print(phi);

    int e = 2;

    do
    {   
        e -= 1;
        e = e << 1;
        e += 1;
      
    } while (!sh_gcd(phi,e));
    
    std::cout << "e\t" << e << "\n";
      
    std::deque<shint> d;
    
    d = sh_calculation_d(phi, e);

    std::cout << "d\t";
    sh_print(d);  

    std::deque<char> real_message;

    std::cout << "message\t";
    real_message = sh_input_char();

    std::pair<std::deque<shint>, std::deque<shint>> cf;
    cf = sh_encryption_char(real_message, e, n);

    std::deque<shint> dc;

    dc = sh_decryption_char(cf, d, n);

    std::cout << "df\t";
    sh_print(dc);


    return 0;
    
    
}
