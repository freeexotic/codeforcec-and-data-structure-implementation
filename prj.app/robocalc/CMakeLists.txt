add_library(robocalc robocalc.cpp robocalc.hpp)
target_link_libraries(robocalc)
set_property(TARGET robocalc PROPERTY CXX_STANDARD 20)
target_include_directories(robocalc PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS robocalc)