add_library(queuelstt INTERFACE queuelstt.hpp)
set_property(TARGET queuealstt PROPERTY CXX_STANDARD 20)
target_include_directories(queuelstt INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS queuelstt)