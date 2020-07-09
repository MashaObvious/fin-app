#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <vector>
#include <string>
#include <variant>

// операции
// счета
// платежи
// планирование
// план
// бюджет
// информация
// категория
// проект
// название
// тег
// валюта
// Пользователь

namespace entities {

struct User{};
struct Money {};

struct Purchase {
    enum class Category {
        food,
        clothes,
        entertainment
    };

    std::string description;
    Category category;
    Money money;
// имя, сумма, дата, категория
};

struct Order {
    size_t from;
    size_t to;
    Money money;
};

using Operation = std::variant<Purchase, Order>;

struct Account{
    size_t id;
    std::vector<Operation> income;
    std::vector<Operation> consumption;
}; // по mbae посмотреть бух учет

class Operations
{
public:
    Operations();
};

}

#endif // OPERATIONS_H
