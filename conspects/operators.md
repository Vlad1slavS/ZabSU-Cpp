## Операторы как члены класса

В C++ операторы могут быть перегружены, что позволяет им работать с пользовательскими типами данных так же, как с встроенными типами. Операторы доступа к членам класса, такие как `.` (точка) и `->` (стрелка), играют важную роль в работе с объектами и указателями на объекты.

### Оператор доступа к членам: `.` (точка)

Оператор `.` используется для доступа к членам класса или структуры. Он применяется к объекту, чтобы получить доступ к его полям и методам.

#### Пример использования оператора `.`

```cpp
#include <iostream>
using namespace std;

class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    void display() {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p(10, 20);
    p.display(); // Использование оператора . для доступа к методу
    cout << "X: " << p.x << ", Y: " << p.y << endl; // Доступ к полям
    return 0;
}
```

### Оператор доступа к членам: `->` (стрелка)

Оператор `->` используется для доступа к членам класса или структуры через указатель на объект. Он позволяет разыменовывать указатель и сразу же получать доступ к его членам.

#### Пример использования оператора `->`

```cpp
#include <iostream>
using namespace std;

class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    void display() {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point* p = new Point(30, 40);
    p->display(); // Использование оператора -> для доступа к методу
    cout << "X: " << p->x << ", Y: " << p->y << endl; // Доступ к полям
    delete p; // Освобождение памяти
    return 0;
}
```

### Перегрузка операторов

C++ позволяет перегружать операторы, включая оператор `->`. Это может быть полезно для создания классов, которые ведут себя как указатели.

#### Пример перегрузки оператора `->`

```cpp
#include <iostream>
using namespace std;

class Resource {
public:
    void show() {
        cout << "Resource accessed!" << endl;
    }
};

class SmartPointer {
private:
    Resource* resource;
public:
    SmartPointer(Resource* r) : resource(r) {}

    // Перегрузка оператора ->
    Resource* operator->() {
        return resource;
    }
};

int main() {
    Resource* res = new Resource();
    SmartPointer sp(res);

    sp->show(); // Использование перегруженного оператора ->

    delete res; // Освобождение памяти
    return 0;
}
```

### Операторы указателей на члены: `.*` и `->*`

C++ также поддерживает указатели на члены классов с помощью операторов `.*` и `->*`. Эти операторы позволяют работать с указателями на члены класса.

#### Пример использования указателей на члены

```cpp
#include <iostream>
using namespace std;

class Test {
public:
    void display() {
        cout << "Display function called!" << endl;
    }
};

int main() {
    Test obj;

    // Указатель на функцию-член
    void (Test::*funcPtr)() = &Test::display;

    // Вызов функции-члена через указатель
    (obj.*funcPtr)(); // Использование оператора .*

    Test* objPtr = &obj;

    (objPtr->*funcPtr)(); // Использование оператора ->*

    return 0;
}
```
