add_executable(test_stackarr test_stackarr.cpp)

add_executable(test_stacklst test_stacklst.cpp)

add_executable(test_queuelst test_queuelst.cpp)

add_executable(test_queuearr test_queuearr.cpp)

add_executable(test_queuelstr test_queuelstr.cpp)


target_link_libraries(test_stackarr stackarr)
target_link_libraries(test_stacklst stacklst)
target_link_libraries(test_queuelst queuelst)
target_link_libraries(test_queuearr queuearr)
target_link_libraries(test_queuelstr queuelstr)
