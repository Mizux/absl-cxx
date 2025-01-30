add_library(foo)
target_sources(foo PRIVATE foo.hpp foo.cpp)
target_include_directories(foo
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)
target_compile_features(foo PUBLIC cxx_std_17)
if(MSVC AND BUILD_SHARED_LIBS)
  target_compile_definitions(foo PUBLIC "FOO_BUILD_DLL")
  target_compile_definitions(foo PRIVATE "FOO_EXPORT")
endif()
set_target_properties(foo PROPERTIES
  VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER foo.hpp)
target_link_libraries(foo PUBLIC
  absl::flags
  absl::status
)
add_library(${PROJECT_NAMESPACE}::foo ALIAS foo)

add_cpp_test(${CMAKE_CURRENT_SOURCE_DIR}/foo_test.cpp)

# Install
install(TARGETS foo
  EXPORT ${PROJECT_NAME}Targets
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/foo
)
