#include "Contact.h"
#include <iostream>

// Конструктор
Contact::Contact(const std::string &name, const std::string &phoneNumber,
                 const std::string &email, const std::string &address)
    : name(name), phoneNumber(phoneNumber), email(email), address(address) {}

// Геттеры
std::string Contact::getName() const { return name; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getEmail() const { return email; }
std::string Contact::getAddress() const { return address; }

// Сеттеры
void Contact::setName(const std::string &newName) {
    if (newName.empty()) {
        std::cerr << "Ошибка: Имя не может быть пустым.\n";
        return;
    }
    name = newName;
}

void Contact::setPhoneNumber(const std::string &newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void Contact::setEmail(const std::string &newEmail) {
    if (newEmail.empty()) {
        std::cerr << "Ошибка: Электронная почта не может быть пустой.\n";
        return;
    }
    if (newEmail.find('@') == std::string::npos) {
        std::cerr << "Ошибка: Неверный адрес электронной почты.\n";
        return;
    }
    email = newEmail; // Изменяем электронную почту только в случае успешной валидации
}

void Contact::setAddress(const std::string &newAddress) {
    if (newAddress.empty()) {
        std::cerr << "Ошибка: Адрес не может быть пустым.\n";
        return;
    }
    address = newAddress;
}

// Методы обновления
void Contact::updatePhoneNumber(const std::string &newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void Contact::updateEmail(const std::string &newEmail) {
    setEmail(newEmail);  // Используем существующий метод setEmail для валидации
}

// Отображение информации
void Contact::displayInfo() const {
    std::cout << "Контакт: " << name << "\n"
              << "Телефон: " << phoneNumber << "\n"
              << "Электронная почта: " << email << "\n"
              << "Адрес: " << address << "\n";
}
