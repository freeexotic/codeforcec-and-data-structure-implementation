add_executable(test_stackarr test_stackarr.cpp)

add_executable(test_stacklst test_stacklst.cpp)

add_executable(test_queuelst test_queuelst.cpp)

add_executable(test_queuearr test_queuearr.cpp)

add_executable(test_bitset test_bitset.cpp)

add_executable(test_stackarrt test_stackarrt.cpp utils.hpp)

add_executable(test_stacklstt test_stacklstt.cpp utils.hpp)

add_executable(test_queuelstt test_queuelstt.cpp utils.hpp)

add_executable(test_queuelstpr test_queuelstpr.cpp)

add_executable(test_robocalc test_robocalc.cpp)

target_link_libraries(test_robocalc robocalc)
target_link_libraries(test_queuelstpr queuelstpr)
target_link_libraries(test_queuelstt queuelstt)
target_link_libraries(test_stacklstt stacklstt)
target_link_libraries(test_stackarrt stackarrt)
target_link_libraries(test_stackarr stackarr)
target_link_libraries(test_stacklst stacklst)
target_link_libraries(test_queuelst queuelst)
target_link_libraries(test_queuearr queuearr)
target_link_libraries(test_bitset bitset)