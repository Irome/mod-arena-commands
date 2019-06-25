CU_SET_PATH("CMAKE_arenaqueue_DIR" "${CMAKE_CURRENT_LIST_DIR}")

AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/ArenaQueCommand.cpp")

AC_ADD_SCRIPT_LOADER("arenaqueue"      "${CMAKE_CURRENT_LIST_DIR}/src/loader.h")

message("-- Arena Que Command CONFIGURED --")