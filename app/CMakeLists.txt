add_executable(app)
target_sources(app PRIVATE app.cpp)
target_include_directories(app PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
target_compile_features(app PRIVATE cxx_std_17)
set_target_properties(app PROPERTIES
  VERSION ${PROJECT_VERSION}
  POSITION_INDEPENDENT_CODE ON
)
# note: macOS is APPLE and also UNIX !
if(APPLE)
  set_target_properties(app PROPERTIES
    INSTALL_RPATH "@loader_path/../${CMAKE_INSTALL_LIBDIR}")
elseif(UNIX AND NOT APPLE)
  set_target_properties(app PROPERTIES
    INSTALL_RPATH "$ORIGIN/../${CMAKE_INSTALL_LIBDIR}")
endif()
target_link_libraries(app PRIVATE
  absl::flags
  absl::flags_parse
  absl::log
  absl::log_globals
  absl::log_initialize
  absl::log_severity
  absl::strings
  AbslCxx::foo
)

add_executable(${PROJECT_NAMESPACE}::app ALIAS app)

if(BUILD_TESTING)
  add_test(NAME cpp_app_test COMMAND app)
endif()

# Install
include(GNUInstallDirs)
install(TARGETS app
  EXPORT ${PROJECT_NAME}Targets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
