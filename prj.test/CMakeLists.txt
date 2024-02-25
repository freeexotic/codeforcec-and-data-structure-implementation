add_executable(test_stackarr test_stackarr.cpp)


add_executable(test_stacklst test_stacklst.cpp)


add_executable(test_queue test_queue.cpp)

target_link_libraries(test_stackarr stackarr)
target_link_libraries(test_stacklst stacklst)
target_link_libraries(test_queue queue)

