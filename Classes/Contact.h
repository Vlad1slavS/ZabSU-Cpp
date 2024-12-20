#ifndef CONTACT_H
#define CONTACT_H

#include <string>

/// Класс для работы с контактами
class Contact
{
private:
    // Поля класса
    std::string name;        // Имя контакта
    std::string phoneNumber; // Номер телефона
    std::string email;       // Электронная почта
    std::string address;     // Адрес контакта

public:
    // Конструктор
    Contact(const std::string &name, const std::string &phoneNumber,
            const std::string &email, const std::string &address);
    Contact();

    // Геттеры
    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    std::string getAddress() const;

    // Сеттеры
    void setName(const std::string &newName);
    void setPhoneNumber(const std::string &newPhoneNumber);
    void setEmail(const std::string &newEmail);
    void setAddress(const std::string &newAddress);

    // Метод отображения информации
    void displayInfo() const;

    std::string toString() const;

    void saveToFile(const std::string &filename) const;
    void loadFromFile(const std::string &filename);

};

#endif // CONTACT_H
