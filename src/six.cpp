#include "../include/six.h"

// === РЕАЛИЗАЦИЯ КОНСТРУКТОРОВ ===

// Конструктор по умолчанию
Six::Six() : arraySize(0), dataArray(nullptr)
{
    std::cout << "Конструктор по умолчанию" << std::endl;
}

bool Six::is_digit_0_to_5(unsigned char x){
    return '0' <= x && x <= '5';
}

    // Конструктор с заполнением
    Six::Six(const size_t &arraySize, unsigned char defaultValue)
{
    std::cout << "Конструктор с заполнением" << std::endl;
    this->arraySize = arraySize;
    this->dataArray = new unsigned char[arraySize];

    // Заполняем массив значением по умолчанию
    for (size_t i = 0; i < arraySize; ++i)
    {
        this->dataArray[i] = defaultValue;
    }
}

// Конструктор из списка инициализации (C++11)
Six::Six(const std::initializer_list<unsigned char> &initialValues)
{
    std::cout << "Конструктор из списка инициализации" << std::endl;
    for (auto i = initialValues.end() - 1; i >= initialValues.begin(); --i)
    {
        std::cout << *i << std::endl;
        if (!is_digit_0_to_5(static_cast<unsigned char>(*i)))
        {
            throw std::invalid_argument("Массив должен содержать шестеричные элементы");
        }
    }
    arraySize = initialValues.size();
    dataArray = new unsigned char[arraySize];

    // Копируем значения из списка инициализации
    size_t index = 0;
    for (auto i = initialValues.end() - 1; i >= initialValues.begin(); --i)
    {
        dataArray[index++] = *i;
    }
}

// Конструктор из строки
Six::Six(const std::string &sourceString)
{
    for (auto i = sourceString.end() - 1; i >= sourceString.begin(); --i)
    {
        // std::cout << *i << std::endl;
        if (!is_digit_0_to_5(*i))
        {
            throw std::invalid_argument("Массив должен содержать шестеричные элементы");
        }
    }
    std::cout << "Конструктор из строки" << std::endl;
    arraySize = sourceString.size();
    dataArray = new unsigned char[arraySize];

    size_t index = 0;
    // Копируем символы из строки
    for (auto i = sourceString.end() - 1; i >= sourceString.begin(); --i)
    {
        dataArray[index++] = *i;
    }
}

// Копирующий конструктор (глубокое копирование)
Six::Six(const Six &other)
{
    std::cout << "Копирующий конструктор" << std::endl;
    arraySize = other.arraySize;
    dataArray = new unsigned char[arraySize];

    // Глубокое копирование данных
    for (size_t i = 0; i < arraySize; ++i)
    {
        dataArray[i] = other.dataArray[i];
    }
}

// Перемещающий конструктор (C++11) - "крадет" ресурсы
Six::Six(Six &&other) noexcept
{
    std::cout << "Перемещающий конструктор" << std::endl;

    // "Крадем" ресурсы у другого объекта
    arraySize = other.arraySize;
    dataArray = other.dataArray;

    // Обнуляем другой объект, чтобы деструктор не освободил память
    other.arraySize = 0;
    other.dataArray = nullptr;
}

// === РЕАЛИЗАЦИЯ ОПЕРАЦИЙ ===

// Сложение массивов (создает новый массив)
Six Six::add(const Six &other)
{
    // Создаем новый массив с размером, равным сумме размеров
    return Six(this->arraySize + other.arraySize, '1');
}

// Вычитание массивов (может выбрасывать исключение)
Six Six::remove(const Six &other)
{
    // Проверяем, можно ли вычесть (размер не может стать отрицательным)
    if (arraySize < other.arraySize)
    {
        throw std::logic_error("Размер массива не может быть отрицательным");
    }

    // Уменьшаем размер
    arraySize -= other.arraySize;

    // Возвращаем ссылку на текущий объект
    return *this;
}

// Сравнение массивов по размеру
bool Six::equals(const Six &other) const
{
    return arraySize == other.arraySize;
}

// Вывод массива в поток
std::ostream &Six::print(std::ostream &outputStream)
{
    for (size_t i = 0; i < arraySize; ++i)
    {
        outputStream << dataArray[i];
    }
    outputStream << '\n';
    return outputStream;
}

// === РЕАЛИЗАЦИЯ ДЕСТРУКТОРА ===

// Деструктор - освобождает динамическую память
Six::~Six() noexcept
{
    std::cout << "Деструктор" << std::endl;

    // Освобождаем память, если она была выделена
    if (dataArray != nullptr)
    {
        delete[] dataArray;
        dataArray = nullptr;
    }

    // Обнуляем размер для безопасности
    arraySize = 0;
}