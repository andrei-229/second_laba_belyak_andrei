#include <string>
#include <iostream>
#include <utility>
#include <algorithm>

// Класс Six - демонстрация управления динамической памятью
// Показывает различные конструкторы, включая перемещающий конструктор (C++11)
// Демонстрирует Правило пяти (Rule of Five) для управления ресурсами

class Six
{
public:
    // === КОНСТРУКТОРЫ ===

    // Конструктор по умолчанию
    Six();

    // Конструктор с заполнением (размер + значение по умолчанию)
    Six(const size_t &arraySize, unsigned char defaultValue = 0);

    // Конструктор из списка инициализации (C++11)
    Six(const std::initializer_list<unsigned char> &initialValues);

    // Конструктор из строки
    Six(const std::string &sourceString);

    // === КОПИРУЮЩИЕ И ПЕРЕМЕЩАЮЩИЕ ОПЕРАЦИИ ===

    // Копирующий конструктор (Правило пяти)
    Six(const Six &other);

    // Перемещающий конструктор (C++11) - Правило пяти
    Six(Six &&other) noexcept;

    // === ОПЕРАЦИИ С МАССИВАМИ ===

    // Сложение массивов (создает новый массив)
    Six add(const Six &other);
    Six operator+(const Six &other);

    bool operator>(const Six &other);
    bool operator<(const Six &other);
    bool operator==(const Six &other);
    bool operator>=(const Six &other);
    bool operator<=(const Six &other);

    // Вычитание массивов (может выбрасывать исключение)
    Six remove(const Six &other);

    // Сравнение массивов по размеру
    bool equals(const Six &other) const;
    int arr_to_int(std::string x);

    // Вывод массива в поток
    std::ostream &print(std::ostream &outputStream);

    // === ДЕСТРУКТОР ===

    // Виртуальный деструктор (Правило пяти)
    virtual ~Six() noexcept;

private:
    // === ДАННЫЕ-ЧЛЕНЫ ===
    bool is_digit_0_to_5(unsigned char x);
    int char_to_int(unsigned char x);
    char int_to_char(int x);
    std::pair<unsigned char*, int> sum(const Six &it, const Six &other);
    std::string make_ans(unsigned char* x, int size);

    size_t arraySize;     // Размер массива
    unsigned char *dataArray; // Указатель на динамический массив
};