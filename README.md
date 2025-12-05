# NPC Game

NPC Game — это небольшая демонстрационная программа на C++, реализующая модель NPC (Non-Player Character) с различными типами (Bear, Elf, Bandit), боевую систему через Visitor, наблюдателей (Observer) для логирования событий и фабрику для создания NPC.

## Проект также включает набор тестов с использованием Google Test.

### Структура проекта
```OOP6/
├─ include/        # Заголовочные файлы
│  ├─ npc.h
│  ├─ factory.h
│  ├─ observer.h
│  └─ visitor.h
├─ src/            # Реализация классов
│  ├─ npc.cpp
│  ├─ factory.cpp
│  ├─ observer.cpp
│  ├─ visitor.cpp
│  └─ main.cpp
├─ tests/          # Тесты Google Test
│  └─ test_npc.cpp
└─ CMakeLists.txt  # CMake конфигурация
```

### Требования
- C++14
- CMake >= 3.14
- Компилятор: GCC, Clang или MSVC
- Для тестов: Google Test (автоматически загружается через CMake)

### Сборка проекта
- Cоздайте папку сборки и перейдите в неё:
```
mkdir build
cd build
```
- Генерация Makefile через CMake:
```
cmake ..
```
- На Windows (MinGW) используйте:
```
cmake -G "MinGW Makefiles" ..
```

### Сборка проекта:

```
cmake --build .
```

- После сборки появятся два исполняемых файла:

```
npc_game — основная программа

test_npc — тесты
```

### Запуск программы
- Основная программа:
```
./npc_game       # Linux / Mac
npc_game.exe     # Windows
```

- Программа создаёт несколько NPC, запускает бои между ними и сохраняет данные в файл npcs.txt. Логи боёв пишутся в log.txt.

#### Запуск тестов:
```
./test_npc       # Linux / Mac
test_npc.exe     # Windows
```

### Тесты проверяют:
- Создание NPC
- Правильность боёв через Visitor
- Логирование через Observer
- Сохранение и загрузку NPC через Factory

### Пример вывода
```
Fight results:
Elf vs Bandit: 0
Bear vs Bandit: 2
Loaded NPCs:
Elf Legolas
Bandit Goblin
Bear Baloo

FightResult: 0 — FirstWins, 1 — SecondWins, 2 — BothDie
```

### Особенности реализации
- Visitor — реализует систему боёв между разными NPC.
- Observer — уведомляет логгер о событиях боёв.
- Factory — создаёт NPC по типу, сохраняет и загружает их из файла.
- Используются умные указатели (std::shared_ptr) для управления памятью.

### Тестирование
- Все тесты написаны с использованием Google Test и проверяют:
- Корректность создания NPC
- Работу логгера
- Результаты боёв
- Сохранение/загрузку через фабрику

Студент: Подгурский Александр
Группа: М8О-203БВ-24

NPC сохраняются в npcs.txt.

Код написан с соблюдением принципов ООП: наследование, полиморфизм, паттерны Visitor и Observer.
