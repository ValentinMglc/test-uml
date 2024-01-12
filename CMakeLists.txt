cmake_minimum_required(VERSION 3.22)
project(r-type)

# Include Conan-generated information
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")
include_directories(${Boost_INCLUDE_DIRS})
add_definitions(-DBOOST_BIND_GLOBAL_PLACEHOLDERS)
find_package(Boost REQUIRED COMPONENTS system thread serialization)
find_package(SFML REQUIRED COMPONENTS graphics window system network audio)

# CLIENT
set(CLIENT r-type_client)
set(CLIENT_SRC_PATH "Client/Sources")
set(CLIENT_INCLUDE_PATH "Client/Include")

# CLIENT SOURCES

set(SRC_CLIENT ${CLIENT_SRC_PATH}/main.cpp
    # Add your sources here
)

set(HPP_CLIENT ${CLIENT_INCLUDE_PATH}/Background.hpp
    # Add your headers here
)

# CLIENT EXECUTABLE
add_executable(${CLIENT} ${SRC_CLIENT} ${HPP_CLIENT})

target_include_directories(${CLIENT} PUBLIC
    ${CLIENT_INCLUDE_PATH}
    ${SFML_INCLUDE_DIR}
    ${Boost_INCLUDE_DIRS}
    Boost::system
)

target_link_libraries(${CLIENT} PRIVATE sfml-graphics sfml-window sfml-system sfml-network sfml-audio ${Boost_LIBRARIES} Boost::system Boost::thread)

# SERVER
set(SERVER r-type_server)
set(SERVER_SRC_PATH "server/")
set(SERVER_INCLUDE_PATH "server/includes/")

# SERVER SOURCES
set(SRC_SERVER ${SERVER_SRC_PATH}/main.cpp
        ${SERVER_SRC_PATH}/server.cpp
        ${SERVER_SRC_PATH}/Timer.cpp
        ${SERVER_SRC_PATH}/GameLoop.cpp
        ${SERVER_SRC_PATH}/Ecs/AISystem.cpp
        ${SERVER_SRC_PATH}/Ecs/Entity.cpp
        ${SERVER_SRC_PATH}/Ecs/EntityManager.cpp
        ${SERVER_SRC_PATH}/Ecs/Sending.cpp
        ${SERVER_SRC_PATH}/Ecs/WeaponSystem.cpp
        ${SERVER_SRC_PATH}/Ecs/PlayerSystem.cpp
        ${SERVER_SRC_PATH}/Ecs/Components/Acceleration.cpp
        ${SERVER_SRC_PATH}/Ecs/Components/Damages.cpp
        ${SERVER_SRC_PATH}/Ecs/Components/Health.cpp
        ${SERVER_SRC_PATH}/Ecs/Components/HitBox.cpp
        ${SERVER_SRC_PATH}/Ecs/Components/Position.cpp
        ${SERVER_SRC_PATH}/Ecs/Components/Drawable.cpp
        ${SERVER_SRC_PATH}/gameEntities/Player.cpp
        ${SERVER_SRC_PATH}/gameEntities/Lobby.cpp
        ${SERVER_SRC_PATH}/gameEntities/LobbyManager.cpp
)

set(HPP_SERVER ${SERVER_INCLUDE_PATH}/server.hpp
        ${SERVER_INCLUDE_PATH}/Timer.hpp
        ${SERVER_INCLUDE_PATH}/GameLoop.hpp
        ${SERVER_INCLUDE_PATH}/ASystem.hpp
        ${SERVER_INCLUDE_PATH}/ISystem.hpp
        ${SERVER_INCLUDE_PATH}/Lobby.hpp
        ${SERVER_INCLUDE_PATH}/LobbyManager.hpp
        ${SERVER_INCLUDE_PATH}/Player.hpp
        ${SERVER_INCLUDE_PATH}/AISystem.hpp
        ${SERVER_INCLUDE_PATH}/TypeEnum.hpp
        ${SERVER_INCLUDE_PATH}/Entity.hpp
        ${SERVER_INCLUDE_PATH}/EntityManager.hpp
        ${SERVER_INCLUDE_PATH}/Sending.hpp
        ${SERVER_INCLUDE_PATH}/WeaponSystem.hpp
        ${SERVER_INCLUDE_PATH}/PlayerSystem.hpp
        ${SERVER_INCLUDE_PATH}/Components/Acceleration.hpp
        ${SERVER_INCLUDE_PATH}/Components/Damages.hpp
        ${SERVER_INCLUDE_PATH}/Components/Health.hpp
        ${SERVER_INCLUDE_PATH}/Components/HitBox.hpp
        ${SERVER_INCLUDE_PATH}/Components/Position.hpp
        ${SERVER_INCLUDE_PATH}/Components/AI.hpp
        ${SERVER_INCLUDE_PATH}/Components/Weapon.hpp
        ${SERVER_INCLUDE_PATH}/Components/IComponent.hpp
        ${SERVER_INCLUDE_PATH}/Components/AComponent.hpp
        ${SERVER_INCLUDE_PATH}/Components/Drawable.hpp
)

# SERVER EXECUTABLE
add_executable(${SERVER} ${SRC_SERVER} ${HPP_SERVER})

target_include_directories(${SERVER} PUBLIC
    ${CMAKE_SOURCE_DIR}/${SERVER_INCLUDE_PATH}
    ${SFML_INCLUDE_DIR}
    ${Boost_INCLUDE_DIRS}  # Add this line
)

target_link_libraries(${SERVER} PRIVATE sfml-graphics sfml-window sfml-system sfml-network ${Boost_LIBRARIES} Boost::system Boost::thread boost_serialization)

# END
# Set default compile flags for GCC
if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    target_compile_options(${CLIENT} PRIVATE -std=c++14 -W -Wall -Wextra)
    target_compile_options(${SERVER} PRIVATE -std=c++14 -W -Wall -Wextra)
endif()

# Set default compile flags for MSVC
if(MSVC)
    message(STATUS "MSVC detected, adding compile flags")
    target_compile_options(${CLIENT} PRIVATE /std:c++14)
    target_compile_options(${SERVER} PRIVATE /std:c++14)
endif()
