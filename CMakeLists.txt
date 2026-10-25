cmake_minimum_required(VERSION 3.12)
project(BM-Tilemap-Editor)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES CMAKE_CONFIGURE_DEPENDS
    "*.cpp"
    "src/*.cpp"
    "src/vendor/*.cpp"
    )

set(name BMTE)
add_executable(${name} ${SOURCES})

target_include_directories(${name} PRIVATE  include/ 
                                            include/vendor/
                                            )
                                            
target_link_directories(${name} PRIVATE lib/)

#Linux
if(UNIX) 
    target_link_libraries(${name} PRIVATE m pthread dl GL raylib X11)
endif()

#Windows
if(WIN32)
    target_link_libraries(${name} PRIVATE opengl32 gdi32 winmm raylib)
endif()
