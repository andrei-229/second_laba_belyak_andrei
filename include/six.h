#include <string>
#include <iostream>
#include <utility>
#include <algorithm>


class Six
{
public:
    Six();

    Six(const std::string &sourceString);

    Six(const Six &other);

    Six(Six &&other) noexcept;

    Six add(const Six &other);
    Six operator+(const Six &other);

    Six sub(const Six &other);
    Six operator-(const Six &other);

    bool operator>(const Six &other);
    bool operator<(const Six &other);
    bool operator==(const Six &other);
    bool operator>=(const Six &other);
    bool operator<=(const Six &other);

    std::ostream &print(std::ostream &outputStream);

    virtual ~Six() noexcept;

private:
    // === ДАННЫЕ-ЧЛЕНЫ ===
    bool is_digit_0_to_5(unsigned char x);
    int char_to_int(unsigned char x);
    char int_to_char(int x);
    std::string sum(const Six &it, const Six &other);
    std::string raz(const Six &it, const Six &other);
    std::string make_ans(std::string x);
    int arr_to_int(std::string x);

    size_t arraySize;     // Размер массива
    std::string dataArray; // Указатель на динамический массив
};