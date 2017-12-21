CMAKE_MINIMUM_REQUIRED(VERSION 3.8)
PROJECT(APEXReplacer C CXX)

################################################################################
# Compiler and linker options
ADD_DEFINITIONS(-Wall -DWIN32_LEAN_AND_MEAN -DUNICODE)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON) 
SET(CMAKE_CXX_STANDARD 11) 

################################################################################
# Sources and libraries
FILE(GLOB UTILITIES "${CMAKE_CURRENT_SOURCE_DIR}/src/utilities/*") 
SET(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/loginwindow.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/ui/loginwindow.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/ui/replaceaetemplate.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/src/ui/replaceaetemplate.h)
 
SET(RESOURCES 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/resource/replaceaetemplate.qrc
  ${CMAKE_CURRENT_SOURCE_DIR}/src/resource/ReplaceAETemplate.rc) 


FIND_PACKAGE(Qt5 COMPONENTS Core Widgets Xml Gui Network REQUIRED) 
qt5_wrap_ui(UI_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/resource/replaceaetemplate.ui ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/loginwindow.ui) 

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
################################################################################
# Compile target
ADD_EXECUTABLE ( ${PROJECT_NAME} 
                 ${UTILITIES}
                 ${UI_HEADERS}
                 ${SOURCES}  
                 ${RESOURCES}
                 ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/main.cpp)
# https://www.kdab.com/using-cmake-with-qt-5/
qt5_use_modules(${PROJECT_NAME} Core Widgets Gui Xml Network)