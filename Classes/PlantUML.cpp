@startuml

class Contact {
    - name: std::string
    - phoneNumber: std::string
    - email: std::string
    - address: std::string

    + Contact(name: std::string, phoneNumber: std::string, email: std::string, address: std::string)
    + Contact()

    + getName(): std::string
    + getPhoneNumber(): std::string
    + getEmail(): std::string
    + getAddress(): std::string

    + setName(newName: std::string): void
    + setPhoneNumber(newPhoneNumber: std::string): void
    + setEmail(newEmail: std::string): void
    + setAddress(newAddress: std::string): void

    + displayInfo(): void
    + toString(): std::string
    + saveToFile(filename: std::string): void
    + loadFromFile(filename: std::string): void
}

@enduml
