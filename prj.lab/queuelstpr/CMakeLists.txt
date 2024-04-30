add_library(queuelstr queuelstr.cpp queuelstr.hpp)
target_link_libraries(queuelstr)
set_property(TARGET queuelstr PROPERTY CXX_STANDARD 20)
target_include_directories(queuelstr PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS queuelstr)