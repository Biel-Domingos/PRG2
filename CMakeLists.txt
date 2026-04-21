cmake_minimum_required(VERSION 3.21)

project(libprg
        LANGUAGES C
        VERSION 0.0.1
        DESCRIPTION "A minimal C library template using Modern CMake")

set(CMAKE_C_STANDARD 17)

add_subdirectory(libprg)

# --- ADICIONE ISSO AQUI ---
add_executable(exercicio_pilha main.c)
target_link_libraries(exercicio_pilha libprg)
# --------------------------

# Configurações extras de CPack (pode manter como está)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()