cmake_minimum_required(VERSION 3.1)

project(fin-app LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

set(GUI "gui/main.qml")
set(ENTITIES "entities/operations.cpp")
set(USECASES "usecases/add_operation.cpp")
set(REPOSITORIES "repositories/accounts_repository.cpp")

set(SOURCES "main.cpp" "application.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${GUI} ${ENTITIES} ${USECASES} ${REPOSITORIES} "qml.qrc")

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Quick)
