cmake_minimum_required(VERSION 3.14)
project(NPCGame)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Автоматическая загрузка GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

if(WIN32)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)
include(GoogleTest)

include_directories(include)

# Основная программа
add_executable(npc_game
    include/npc.h
    include/factory.h
    include/observer.h
    include/visitor.h
    src/npc.cpp
    src/factory.cpp
    src/observer.cpp
    src/visitor.cpp
    src/main.cpp
)

# Тесты
add_executable(test_npc
    include/npc.h
    include/factory.h
    include/observer.h
    include/visitor.h
    src/npc.cpp
    src/factory.cpp
    src/observer.cpp
    src/visitor.cpp
    tests/test_npc.cpp
)

target_link_libraries(test_npc gtest gtest_main)
gtest_discover_tests(test_npc)

# Включаем строгие предупреждения
target_compile_options(npc_game PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(test_npc PRIVATE -Wall -Wextra -Wpedantic)
