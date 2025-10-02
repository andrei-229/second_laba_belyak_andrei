#include "../include/six.h"

Six::Six() : arraySize(0), dataArray("")
{
    std::cout << "Конструктор по умолчанию" << std::endl;
}

bool Six::is_digit_0_to_5(unsigned char x){
    return '0' <= x && x <= '5';
}

int Six::char_to_int(unsigned char x) {return int(x) - 48;}
char Six::int_to_char(int x) {return char(x+48);}

int Six::arr_to_int(std::string x){
    int s = 0;
    int k = 1;
    for (auto i = x.begin(); i < x.end(); ++i){
        s += char_to_int(*i)*k;
        k *= 10;
    }
    return s;
}

std::string Six::make_ans(std::string x){
    std::string ans = "";
    int index = 0;
    for (auto i = x.end() - 1; i >= x.begin(); --i)
    {
        ans += *i;
    }
    return ans;
}

// std::string Six::make_ans(unsigned char *x, int size)
// {
//     std::string result;
//     // Собираем строку в правильном порядке
//     for (int i = size - 1; i >= 0; --i)
//     {
//         result += x[i];
//     }
//     delete[] x; // Очищаем память
//     return result;
// }

std::string Six::sum(const Six &it, const Six &other)
{
    int s = 0;
    size_t ost = 0;

    size_t other_size = other.arraySize;
    size_t my_size = it.arraySize;

    if (my_size > other_size){return sum(other, it);}

    int k = 1;
    size_t cnt = 0;
    size_t i = 0;
    int moi, oth, tmp_s;

    for (;i < my_size; ++i){
        moi = char_to_int(it.dataArray[i]);
        oth = char_to_int(other.dataArray[i]);

        s += ((moi + oth + ost) % 6) * k;
        ost = (moi + oth + ost) / 6;

        k *= 10;
        cnt += 1;
    }
    for (;i < other_size; ++i){
        oth = char_to_int(other.dataArray[i]);

        s += ((oth+ost) % 6) * k;
        ost = (oth+ost) / 6;

        k *= 10;
        cnt += 1;
    }
    s += ost * k;
    cnt += (ost) ? 1 : 0;

    std::string arr = "";
    int index = 0;

    while (s > 0){
        arr += int_to_char(s%10);
        s /= 10;
    }
    return arr;
}

std::string Six::raz(const Six &it, const Six &other)
{
    if (arr_to_int(it.dataArray) <= arr_to_int(other.dataArray))
    {
        std::string arr = "0";
        return arr;
    }
    int s = 0;
    size_t ost = 0;

    size_t other_size = other.arraySize;
    size_t my_size = it.arraySize;

    int k = 1;
    size_t cnt = 0;
    size_t i = 0;
    int moi, oth, tmp_s;

    for (; i < other_size; ++i)
    {
        moi = char_to_int(it.dataArray[i]);
        oth = char_to_int(other.dataArray[i]);

        if (moi < oth && !ost){
            s += (moi+6-oth)*k;
            ost = 1;
        }
        else if (!moi && oth && ost){
            s += (5-oth)*k;
        }
        else if (moi-ost < oth && ost){
            s += (moi-ost+6-oth)*k;
        }
        else{
            s += (moi-ost-oth)*k;
            ost = 0;
        }
        k *= 10;
        cnt += 1;
        
    }
    for (; i < my_size; ++i)
    {
        moi = char_to_int(it.dataArray[i]);
        if (!moi && ost){
            s += 5*k;
        }
        else{
            moi -= ost;
            ost = 0;
        }
        s += moi * k;
        k *= 10;
        cnt += 1;
    }
    cnt -= (moi) ? 0 : 1;
    std::string arr = "";
    int index = 0;
    while (s > 0)
    {
        arr += int_to_char(s % 10);
        s /= 10;
    }
    return arr;
}


Six::Six(const std::string &sourceString)
{
    for (auto i = sourceString.end() - 1; i >= sourceString.begin(); --i)
    {
        if (!is_digit_0_to_5(*i))
        {
            throw std::invalid_argument("Массив должен содержать шестеричные элементы");
        }
    }
    std::cout << "Конструктор из строки" << std::endl;
    arraySize = sourceString.size();
    dataArray = "";

    size_t index = 0;
    for (auto i = sourceString.end() - 1; i >= sourceString.begin(); --i)
    {
        dataArray += *i;
    }
}

Six::Six(const Six &other)
{
    std::cout << "Копирующий конструктор" << std::endl;
    arraySize = other.arraySize;
    dataArray = "";
    for (auto i = other.dataArray.begin(); i < other.dataArray.end(); ++i)
    {
        dataArray += *i;
    }
}
Six::Six(Six &&other) noexcept
{
    std::cout << "Перемещающий конструктор" << std::endl;

    arraySize = other.arraySize;
    dataArray = other.dataArray;

    other.arraySize = 0;
    other.dataArray = "";
}

Six Six::add(const Six &other)
{
    std::string para = sum(*this, other);
    std::string ans = make_ans(para);
    return Six{ans};
}

Six Six::operator+(const Six &other){
    std::string para = sum(*this, other);
    std::string ans = make_ans(para);
    return Six{ans};
}

Six Six::sub(const Six &other)
{
    std::string para = raz(*this, other);
    std::string ans = make_ans(para);
    return Six{ans};
}

Six Six::operator-(const Six &other){
    std::string para = raz(*this, other);
    std::string ans = make_ans(para);
    return Six{ans};
}

bool Six::operator>(const Six &other){
    return arr_to_int(this->dataArray) > arr_to_int(other.dataArray);
}

bool Six::operator<(const Six &other){
    return arr_to_int(this->dataArray) < arr_to_int(other.dataArray);
}

bool Six::operator==(const Six &other){
    return arr_to_int(this->dataArray) == arr_to_int(other.dataArray);
}
bool Six::operator>=(const Six &other){
    return arr_to_int(this->dataArray) >= arr_to_int(other.dataArray);
}
bool Six::operator<=(const Six &other){
    return arr_to_int(this->dataArray) <= arr_to_int(other.dataArray);
}

std::ostream &Six::print(std::ostream &outputStream)
{
    for (auto i = dataArray.end() - 1; i >= dataArray.begin(); --i)
    {
        outputStream << *i;
    }
    if (arraySize)
    {
        outputStream << '\n';
    }
    return outputStream;
}

Six::~Six() noexcept
{
    std::cout << "Деструктор" << std::endl;

    if (dataArray != "")
    {
        dataArray = "";
    }

    arraySize = 0;
}