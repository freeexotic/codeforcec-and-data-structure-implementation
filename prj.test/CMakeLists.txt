add_executable(test_stackarr test_stackarr.cpp)
add_executable(test_stacklst test_stacklst.cpp)

target_link_libraries(test_stackarr stackarr)
target_link_libraries(test_stacklst stacklst)

