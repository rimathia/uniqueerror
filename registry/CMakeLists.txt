add_library(registry SHARED include/registry/registry.h registry.cpp)
target_include_directories(registry PUBLIC include)
target_link_libraries(registry fmt)
