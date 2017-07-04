project(PID)

cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(sources src/PID.cpp src/main.cpp)


if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 

include_directories(/usr/local/include)
include_directories(/usr/local/opt/openssl/include)
link_directories(/usr/local/lib)
link_directories(/usr/local/opt/openssl/lib)
link_directories(/usr/local/Cellar/libuv/1.11.0/lib)

endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 


add_executable(pid ${sources})

target_link_libraries(pid z ssl uv uWS)

#install (TARGETS uWS ARCHIVE DESTINATION /usr/local/lib LIBRARY DESTINATION /usr/local/lib)
#install (FILES src/HTTPSocket.h src/Network.h src/Parser.h src/Server.h src/SocketData.h src/uWS.h
#        src/UTF8.h src/WebSocket.h DESTINATION /usr/local/include/uWS)