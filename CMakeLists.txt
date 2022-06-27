cmake_minimum_required(VERSION 3.16)

project(testdb VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH "/opt/qt6.3/6.3.1/gcc_64")

find_package(Qt6 6.2 COMPONENTS Quick Widgets REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Sql Widgets)

qt_add_executable(apptestdb
        main.cpp
        headers/connection.h
        headers/table/mysortfilterproxymodel.h
        headers/window.h
        headers/sidebar.h
        headers/menu/querydialog.h
        headers/menu/codeeditor.h
        headers/table/tableeditor.h
        headers/menu/linenumberarea.h

        sources/table/tableeditor.cpp
        sources/table/mysortfilterproxymodel.cpp
        sources/window.cpp
        sources/sidebar.cpp
        sources/menu/querydialog.cpp
        sources/menu/codeeditor.cpp
        )


set_target_properties(apptestdb PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )

target_compile_definitions(apptestdb PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(apptestdb PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Sql
        Qt::Widgets
        )
