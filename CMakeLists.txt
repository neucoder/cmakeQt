cmake_minimum_required(VERSION 3.10)
project(cmakeQt)

set(CMAKE_CXX_STANDARD 11)





set (CMAKE_PREFIX_PATH "N:\\QT\\5.10.0\\mingw53_32\\")




# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)


# Tell CMake to create the helloworld executable
#add_executable(helloworld WIN32 ${helloworld_SRCS})


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(Exerc)

aux_source_directory(. SRC)
add_executable(main ${SRC})
# Use the Widgets module from Qt 5
target_link_libraries(main Qt5::Widgets Exer)