#include <string>
#include <iostream>

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

    // Вычитание массивов (может выбрасывать исключение)
    Six remove(const Six &other);

    // Сравнение массивов по размеру
    bool equals(const Six &other) const;

    // Вывод массива в поток
    std::ostream &print(std::ostream &outputStream);

    // === ДЕСТРУКТОР ===

    // Виртуальный деструктор (Правило пяти)
    virtual ~Six() noexcept;

private:
    // === ДАННЫЕ-ЧЛЕНЫ ===
    bool is_digit_0_to_5(unsigned char x);
    size_t arraySize;     // Размер массива
    unsigned char *dataArray; // Указатель на динамический массив
};