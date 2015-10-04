cmake_minimum_required(VERSION 2.6)
project(_1byte)
set (CMAKE_CXX_FLAGS "-std=c++11")

#big thanks to this thread: http://stackoverflow.com/questions/7046956/populating-srcs-from-cmakelists-txt-in-subdirectories
macro (add_sources)
    file (RELATIVE_PATH _relPath "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach (_src ${ARGN})
        if (_relPath)
            message("added source ${_relPath}/${_src}")
            list (APPEND SRCS "${_relPath}/${_src}")
        else()
        message("added source ${_src}")
            list (APPEND SRCS "${_src}")
        endif()
    endforeach()
    if (_relPath)
        set (SRCS ${SRCS} PARENT_SCOPE)
    endif()
endmacro()
#

add_sources(main.cpp)


add_executable(_1byte ${SRCS})
install(TARGETS _1byte RUNTIME DESTINATION bin)
