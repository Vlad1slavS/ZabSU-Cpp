#include "Contact.h"
#include <iostream>
#include <sstream>

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
        throw std::invalid_argument("Имя контакта не может быть пустым.");
        return;
    }
    name = newName;
}
 
// Сеттер поля phoneNumber значением newPhoneNumber
void Contact::setPhoneNumber(const std::string &newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

// Сеттер поля email значением newEmail
void Contact::setEmail(const std::string &newEmail) {
    if (newEmail.empty()) {
        throw std::invalid_argument("Электронная почта контакта не может быть пустой.");
        return;
    }
    if (newEmail.find('@') == std::string::npos) {
        throw std::invalid_argument("Некорректная электронная почта.");
        return;
    }
    email = newEmail; // Изменяем электронную почту только в случае успешной валидации
}

// Сеттер поля address значением newAddress
void Contact::setAddress(const std::string &newAddress) {
    if (newAddress.empty()) {
        throw std::invalid_argument("Адрес контакта не может быть пустой.");
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

std::string Contact::toString() const {
    std::ostringstream oss;
    oss << "Контакт: " << name << "\n"
        << "Телефон: " << phoneNumber << "\n"
        << "Электронная почта: " << email << "\n"
        << "Адрес: " << address << "\n";
    return oss.str();
}
