// Автор: Степанов Владислав ИВТ-23
#include <iostream>
#include <string>
#include <cassert>
#include "Contact.h"

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

    // Проверка методов обновления
    contact.updatePhoneNumber("111-222-3333");
    assert(contact.getPhoneNumber() == "111-222-3333");

    contact.updateEmail("ivanov@newmail.com");
    assert(contact.getEmail() == "ivanov@newmail.com");

    // Проверка валидации ввода
    contact.setName("");
    assert(contact.getName() == "Петр Петров"); // Имя не должно измениться

    contact.setEmail("");
    assert(contact.getEmail() == "ivanov@newmail.com"); // Почта не должна измениться

    contact.setEmail("ivanexample.com");
    assert(contact.getEmail() == "ivanov@newmail.com"); // Почта не должна измениться

    contact.setAddress("");
    assert(contact.getAddress() == "Улица Чехова, д. 2"); // Адрес не должен измениться

}

int main() {
    // Проверка класса
    testContactClass(); // Вызов функции для тестирования
    std::cout << "Все тесты пройдены успешно." << std::endl; 

    // Основной код программы
    string asp = "==================================";

    Contact contact1("Иван Иванов", "123-456-7890", "ivan@example.com", "Улица Пушкина, д. 1");
    Contact contact2("Мария Смирнова", "987-654-3210", "maria@example.com", "Улица Лермонтова, д. 2");

    // Динамическое создание объекта
    cout << asp << endl;
    cout << "Динамическое создание объекта" << endl;
    Contact *contact3 = new Contact("Иван Иванов", "123-456-7890", "ivan@example.com", "Улица Пушкина, д. 1");  
    Contact *contact4 = new Contact("Мария Смирнова", "987-654-3210", "maria@example.com", "Улица Лермонтова, д. 2");

    // Отображаем информацию о контактах
    contact3->displayInfo();
    std::cout << std::endl;
    contact4->displayInfo();

    cout << asp << endl;

    // Отображаем информацию о контактах
    cout << "Пример использования класса Contact" << endl;
    contact1.displayInfo();
    std::cout << std::endl;
    contact2.displayInfo();

    // Обновляем номер телефона и почту контакта
    contact1.updatePhoneNumber("111-222-3333");
    contact2.updateEmail("maria.s@example.com");

    // Освобождение памяти
    delete contact3;
    delete contact4;

    return 0;
}
