 cmake_minimum_required(VERSION 3.18.4)

 set(This scrapper)

 project(${This} CXX)
 set(CMAKE_CXX_STANDARD 14)
 set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
 link_directories(${CMAKE_SOURCE_DIR}/lib)

 enable_testing()

 add_subdirectory(googletest)

 set(Headers
 
 )

 set(Sources
 
    main.cpp
 )


 add_library(${This} STATIC ${Sources} ${Headers})

 add_subdirectory(test)
 add_executable(main ${Sources})
 target_link_libraries(main ${CMAKE_SOURCE_DIR}/lib/libcurl.a)
 target_link_libraries(main ${CMAKE_SOURCE_DIR}/lib/libcurl.dll.a)