# RSA 
## Структура проекта
- `projectCL_RSA` - папка где расположены файлы.
- `main.cpp` - файл для входа в программу.
- `rsa.cpp` - файл с реализациями всех функций.
- `rsa.h` - Заголовочный файл с объявлениями функций.
- `CMakeLists.txt` — Файл для сборки проекта с использованием CMake.
---
## Установка библиотеки Boost
- На Linux
    - sudo apt-get install libboost-all-dev
- На Windows
    - Перейдите на официальный сайт Boost и загрузите последнюю версию архива www.boost.org

---
## Функции
- `bool IsDigitSimple(cpp_int n);` - Проверка на то является ли число простым
- `cpp_int ModulStepen(cpp_int base, cpp_int exp, cpp_int mod);` -  Быстрое возведение в степень по модулю 
- `cpp_int KeyGen(cpp_int p, cpp_int q);` - Генерация закрытой экспоненты d
- `cpp_int TextToNum(const std::string &text);` - Преобразование строки в число
- `std::string NumToText(cpp_int num);` - Преобразование числа в строку 
- `cpp_int EncBlock(cpp_int m, cpp_int e, cpp_int n);` - Шифрование блока текста (Размер блока будет соответствовать размеру сообщения, но при желании его можно изменить)
- `cpp_int DecBlock(cpp_int c, cpp_int d, cpp_int n);` - Дешифрование блока текста
- `std::vector<cpp_int> EncText(const std::string &message, cpp_int e, cpp_int n,cpp_int s);` - Шифрование текста
- `std::string DecText(const std::vector<cpp_int> &encryptedBlocks, cpp_int d, cpp_int n);` - Дешифрование текста