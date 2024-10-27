#include <iostream>
#include <string>

class Contact
{
private:
    std::string name;        // Имя контакта
    std::string phoneNumber; // Номер телефона
    std::string email;       // Электронная почта
    std::string address;     // Адрес контакта

public:
    // Конструктор для инициализации полей класса
    Contact(const std::string &name, const std::string &phoneNumber,
            const std::string &email, const std::string &address)
        : name(name), phoneNumber(phoneNumber), email(email), address(address) {}

    // Метод для получения имени контакта
    std::string getName() const
    {
        return name;
    }

    // Метод для получения номера телефона
    std::string getPhoneNumber() const
    {
        return phoneNumber;
    }

    // Метод для получения электронной почты
    std::string getEmail() const
    {
        return email;
    }

    // Метод для получения адреса
    std::string getAddress() const
    {
        return address;
    }

    // Сеттер для обновления имени
    void setName(const std::string &newName)
    {
        name = newName;
    }

    // Сеттер для обновления номера телефона
    void setPhoneNumber(const std::string &newPhoneNumber)
    {
        phoneNumber = newPhoneNumber;
    }

    // Сеттер для обновления электронной почты
    void setEmail(const std::string &newEmail)
    {
        email = newEmail;
    }

    // Сеттер для обновления адреса
    void setAddress(const std::string &newAddress)
    {
        address = newAddress;
    }

    // Метод для обновления номера телефона
    void updatePhoneNumber(const std::string &newPhoneNumber)
    {
        phoneNumber = newPhoneNumber;
    }

    // Метод для обновления электронной почты
    void updateEmail(const std::string &newEmail)
    {
        email = newEmail;
    }

    // Метод для отображения информации о контакте
    void displayInfo() const
    {
        std::cout << "Контакт: " << name << "\n"
                  << "Телефон: " << phoneNumber << "\n"
                  << "Электронная почта: " << email << "\n"
                  << "Адрес: " << address << "\n";
    }
};

// Пример использования класса Contact
int main()
{
    Contact contact1("Иван Иванов", "123-456-7890", "ivan@example.com", "Улица Пушкина, д. 1");
    Contact contact2("Мария Смирнова", "987-654-3210", "maria@example.com", "Улица Лермонтова, д. 2");

    // Отображаем информацию о контактах
    contact1.displayInfo();
    std::cout << std::endl;
    contact2.displayInfo();

    // Обновляем номер телефона и почту контакта
    contact1.updatePhoneNumber("111-222-3333");
    contact2.updateEmail("maria.s@example.com");

    // Отображение обновленной информации
    std::cout << "\nОбновленная информация:\n";
    contact1.displayInfo();
    std::cout << std::endl;
    contact2.displayInfo();

    return 0;
}
