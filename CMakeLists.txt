project(Peggle)

# CMake 3.* necessario per Qt
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# ottengo tutti i sorgenti
file(GLOB my_sources *.h *.cpp *.qrc)

# attiva il Resource Compiler (RCC)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

# aggiungo eseguibile
add_executable(Peggle  ${my_sources} resources.qrc)

# verifico l'esistenza delle librerie Qt necessarie
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(box2d REQUIRED)

include_directories(Box2D)

# collego le librerie Qt con l'eseguibile
target_link_libraries(Peggle Qt5::Widgets Qt5::Multimedia box2d)

add_library(box2d STATIC IMPORTED)
set_property(TARGET box2d PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/library/box2d.lib)
target_link_libraries(Peggle box2d)