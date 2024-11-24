// Автор: Степанов Владислав ИВТ-23
#include <iostream>
#include <string>
#include <cassert>
#include "Contact.h"
#include <vector>

using namespace std;

// Функция для тестирования класса Contact
void testContactClass() {
    // Проверка конструктора и геттеров
    Contact contact("Иван Иванов", "123-456-7890", "ivan@example.com", "Улица Пушкина, д. 1");
    assert(contact.getName() == "Иван Иванов");
    assert(contact.getPhoneNumber() == "123-456-7890");
    assert(contact.getEmail() == "ivan@example.com");
    assert(contact.getAddress() == "Улица Пушкина, д. 1");

    // Проверка сеттеров
    contact.setName("Петр Петров");
    assert(contact.getName() == "Петр Петров");

    contact.setPhoneNumber("098-765-4321");
    assert(contact.getPhoneNumber() == "098-765-4321");

    contact.setEmail("petr@example.com");
    assert(contact.getEmail() == "petr@example.com");

    contact.setAddress("Улица Чехова, д. 2");
    assert(contact.getAddress() == "Улица Чехова, д. 2");

}

int main() {
    try {
    // Проверка класса
    testContactClass(); // Вызов функции для тестирования

    // Статический объект
    Contact contact1("Иван Иванов", "123-456-7890", "ivan@example.com", "Улица Пушкина, д. 1");
    Contact contact2("Мария Смирнова", "987-654-3210", "maria@example.com", "Улица Лермонтова, д. 2");

    // Динамическое создание объекта
    Contact *contact3 = new Contact("Иван Иванов", "123-456-7890", "ivan@example.com", "Улица Пушкина, д. 1");  
    Contact *contact4 = new Contact("Мария Смирнова", "987-654-3210", "maria@example.com", "Улица Лермонтова, д. 2");

    //  Вектор объектов
    std::vector<Contact> contacts;
    contacts.push_back(contact1);

    // Статическое создание массива объектов.
    Contact staticContacts[] = {
        Contact("Иван Иванов", "123-456-7890", "ivan@example.com", "Улица Пушкина, д. 1"),
        Contact("Мария Смирнова", "987-654-3210", "maria@example.com", "Улица Лермонтова, д. 2")
    };

    // Создание массива указателей на объекты
    Contact** dynamicContacts = new Contact*[2];
    dynamicContacts[0] = new Contact("Алексей Алексеев", "555-1234", "alex@example.com", "Улица Кирова, д. 3");
    dynamicContacts[1] = new Contact("Ольга Орлова", "555-5678", "olga@example.com", "Улица Мира, д. 4");


    dynamicContacts[0]->saveToFile("input.txt");

    contact1.toString();
    
    contacts[0].loadFromFile("input.txt");
    contact2.saveToFile("output.txt");

    // Освобождение памяти
    delete contact3;
    delete contact4;
    delete dynamicContacts[0];
    delete dynamicContacts[1];
    delete[] dynamicContacts;

    } catch (const std::exception& e) {
        std::cerr << "Произошла ошибка: " << e.what() << std::endl;
    }

    return 0;
}
