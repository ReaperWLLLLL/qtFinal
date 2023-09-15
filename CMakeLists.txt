cmake_minimum_required(VERSION 3.26)
project(qtFinal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "G:/software/QT/6.5.2/mingw_64")

#设置lapacke库
set(LAPACK_LIBRARIES "./lib")
set(LAPACK_INCLUDE_DIR "./lib/include")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

#添加include路径
include_directories(
        ${PROJECT_SOURCE_DIR}/ui
        ${LAPACK_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/class
)

link_directories(${LAPACK_LIBRARIES})

link_libraries(ws2_32)

add_executable(qtFinal main.cpp
        lib/include/lapacke_example_aux.cpp
        class/Mesh.cpp
        class/El2no.cpp
        class/Component.cpp
        class/Bd2no.cpp
        class/No2xy.cpp
        lib/include/sqlite3.c
        ui/mainwindow.cpp
        ui/mainwindow.h
        ui/mainwindow.ui
        lib/include/TCPListener.cpp
)

target_link_libraries(qtFinal
        Qt::Core
        Qt::Gui
        Qt::Widgets
        libblas.dll
        libgcc_s_seh_64-1.dll
        libgfortran_64-3.dll
        liblapack.dll
        liblapacke.dll
        liblapacke.lib
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
