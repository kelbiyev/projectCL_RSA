#include "rsa.h"

std::deque<shint> sh_input(){
    std::string input;
    std::deque<shint> input_deque;

    std::cin >> input;

    for(char digit: input){
        if(digit >= '0' && digit <= '9'){
            input_deque.push_back(digit - '0');
        }
    }
    std::reverse(input_deque.begin(), input_deque.end());

    return input_deque;
}

void sh_print(const std::deque<shint> &v){
    for(auto iter = v.rbegin(); iter != v.rend(); iter++){
        std::cout << *iter << " ";
    }
    std::cout << "\n";
}

std::deque<shint> sh_mp(const std::deque<shint> &first, const std::deque<shint> &second){
    std::deque<shint> mp_deque;
    mp_deque.resize(first.size() + second.size() + 1);
    for(size_t i = 0; i != first.size(); i++){
        int transfer = 0;
        for(size_t j = 0; j != second.size(); j++){
            int mp = first[i] * second [j] + mp_deque[i + j] + transfer;
            mp_deque[i + j] = mp % 10;
            transfer = mp / 10;
        }
        mp_deque[i + second.size()] += transfer;
    }
    while(mp_deque.back() == 0){
        mp_deque.pop_back();
    }
   
    return mp_deque;
}

bool sh_gcd(const std::deque<shint> &first, int e){
    int mod_gcd_int = sh_mod_int(first, e);
    int gcd_res = sh_evklid(mod_gcd_int, e);
    return gcd_res == 1;
}

int sh_mod_int(std::deque<shint> first, int e){
	int mod = 0;
	std::reverse(first.begin(), first.end());
	for(int digit: first){
		mod = (mod * 10 + digit) % e; 
	}
	
	return mod;
}

int sh_evklid(int a, int b){
	while(b != 0){
		int t = b;
		b = a % b;
		a = t;
	}
	
	return a;
}

std::deque<shint> sh_pow(const std::deque<shint> &first, int e, const std::deque<shint> &n){
    std::deque<shint> pow_deque = {1}; 
    std::deque<shint> mod_deque = sh_mod(first, n);
    while (e > 0){
        if (e % 2 == 1){
            pow_deque = sh_mod(sh_mp(pow_deque, mod_deque), n); 
		}
        mod_deque = sh_mod(sh_mp(mod_deque, mod_deque), n); 
        e >>= 1;
    }

    return pow_deque;
}

std::deque<shint> sh_mod(std::deque<shint> first, std::deque<shint> second){
    auto[chast, ostatok] = sh_divide(first, second);
    return ostatok;
}

std::pair<std::deque<shint>, std::deque<shint>> sh_divide(const std::deque<shint> &first, const std::deque<shint> &second){
    std::deque<shint> chast;
    std::deque<shint> ostatok;
    for (int i = first.size() - 1; i >= 0; i--){
        ostatok.insert(ostatok.begin(), first[i]);
        while (ostatok.size() > 1 && ostatok.back() == 0){
            ostatok.pop_back();
        }
        int ch = 0;
        while (sh_compare(second, ostatok)){
            sh_subtract(ostatok, second);
            ch++;
        }
        chast.push_back(ch);
    }

    std::reverse(chast.begin(), chast.end());

    while (chast.size() > 1 && chast.back() == 0){
        chast.pop_back();
    } 

    return {chast, ostatok};
}

bool sh_compare(const std::deque<shint> &first, const std::deque<shint> &second){
    if (first.size() != second.size()){
        return first.size() < second.size();
    } 
    for (int i = first.size() - 1; i >= 0; i--){
        if (first[i] != second[i]){
            return first[i] < second[i];
        } 
    }

    return true;
}

void sh_subtract(std::deque<shint> &first, const std::deque<shint> &second){
    int t = 0;
    for(size_t i = 0; i < first.size(); i++){
        int p = t;
        if(i < second.size()){
            p += second[i];
        }
        if(first[i] < p){
            first[i] += 10;
            t = 1;
        }else{
            t = 0;
        }
        first[i] -= p;
    }
    while(first.back() == 0){
        first.pop_back();
    }
}

//---------------------------------------------------------------------------------

std::deque<shint> sh_division_int(std::deque<shint> first, int e){
    std::deque<shint> divider_deque;
    std::reverse(first.begin(), first.end());
    int divider = 0;
    for (int digit : first){
        divider = (divider * 10) + digit;
        int res = divider / e;
        divider_deque.push_back(res);
        divider %= e;
    }


    while (!divider_deque.empty() && divider_deque[0] == 0){
        divider_deque.erase(divider_deque.begin());
    }
    std::reverse(divider_deque.begin(), divider_deque.end());

    return divider_deque;
}

std::deque<shint> sh_pow_deque(const std::deque<shint> &first, std::deque<shint> d, const std::deque<shint> &n){
    std::deque<shint> pow_deque = {1}; 
    std::deque<shint> mod_deque = sh_mod(first, n); 
    std::deque<shint> two = {2};
    std::deque<shint> nolik = {0};
    while (!sh_equal(nolik, d)){
        auto[chast, ostatok] = sh_divide(d, two);

        if (sh_equal({1}, ostatok)){
            pow_deque = sh_mod(sh_mp(pow_deque, mod_deque), n); 
		}
        mod_deque = sh_mod(sh_mp(mod_deque, mod_deque), n); 
        d = chast;
    }

    return pow_deque;
}

bool sh_equal(const std::deque<shint> &first, const std::deque<shint> &second){
    return first == second;
}

std::deque<char> sh_input_char(){
    std::string input;
    std::deque<char> input_deque;
    std::cin >> input;
    for(char symbol: input){
        input_deque.push_back(symbol);
    }

    return input_deque;
}

std::pair<std::deque<shint>, std::deque<shint>> sh_encryption_char(const std::deque<char> &message, int e, const std::deque<shint> &n){
    std::pair<std::deque<shint>, std::deque<shint>> result;
    std::deque<shint> res;
    std::deque<shint> count;
    for(char symbol: message){
		int count_int = 0;
		int sym = symbol;
		std::cout << sym << "\n";
		while(sym > 0){
			res.push_back(sym % 10);
			sym /= 10;
			count_int++;
		}
		count.push_back(count_int);
	}
	std::deque<shint> res_pow;
	res_pow = sh_pow(res, e, n);
	std::cout << "res_pow\t";
	sh_print(res_pow);
	result.first = res_pow;
	result.second = count;    

    return result;
}

std::deque<shint> sh_decryption_char(std::pair<std::deque<shint>, std::deque<shint>> &cmessage, std::deque<shint> &d, const std::deque<shint> &n){
    std::deque<shint> res;
    std::string output;
    res = sh_pow_deque(cmessage.first, d, n);
    std::deque<shint> t_int = res;
    std::reverse(cmessage.second.begin(), cmessage.second.end());
    for(size_t i = 0; i < cmessage.second.size(); i++){
		int count;
		int count_erase;
		count = cmessage.second[i];
		count_erase = cmessage.second[i];
		int num = 0;
		for(auto iter = t_int.end() - 1; iter != t_int.begin() - 1; iter--){
			num = (num * 10) + *iter;
			count--;

            if(count < 1){
				break;
			}
		}
        t_int.erase(t_int.end() - count_erase, t_int.end());
		output += static_cast<char> (num);
	}
	std::reverse(output.begin(), output.end());
	std::cout << "output\t" << output << "\n";

    return res;
}

//----------------------------------------------------------------------------------

std::deque<shint> sh_calculation_d(const std::deque<shint> &phi, int e){
    std::deque<shint> k {1};
    std::deque<shint> first;
    while(1){
        first = sh_mp(phi, k);
        ++first;
        int t = sh_mod_int(first, e);

        if(t == 0){
            break;
        }
        ++k;
    }
    std::cout << "k\t";
    sh_print(k);
    std::deque<shint> d;
    d = sh_division_int(first, e);

    return d;
}

std::deque<shint> &operator ++(std::deque<shint> &first){
    shint t = 0;
    first[0] += 1;
    for(size_t i = 0; i != first.size(); i++){
        first[i] += t; 
        t = 0;
        if(first[i] > 9){
            t = 1;
            first[i] -= 10;
        }
    }
    if(t == 1){
        first.push_back(1);
    }

    return first;
}