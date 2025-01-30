include(FetchContent)
set(FETCHCONTENT_QUIET OFF)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
set(BUILD_SHARED_LIBS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(BUILD_TESTING OFF)
set(CMAKE_Fortran_COMPILER OFF)

# ##############################################################################
# ZLIB
# ##############################################################################
if(BUILD_ZLIB)
  message(CHECK_START "Fetching ZLIB")
  list(APPEND CMAKE_MESSAGE_INDENT "  ")
  set(ZLIB_BUILD_EXAMPLES OFF)
  FetchContent_Declare(
    ZLIB
    GIT_REPOSITORY "https://github.com/madler/ZLIB.git"
    GIT_TAG "v1.3.1"
    PATCH_COMMAND git apply --ignore-whitespace
    "${CMAKE_CURRENT_LIST_DIR}/../../patches/ZLIB-v1.3.1.patch")
  FetchContent_MakeAvailable(ZLIB)
  list(POP_BACK CMAKE_MESSAGE_INDENT)
  message(CHECK_PASS "fetched")
endif()

# ##############################################################################
# ABSEIL-CPP
# ##############################################################################
if(BUILD_absl)
  message(CHECK_START "Fetching Abseil-cpp")
  list(APPEND CMAKE_MESSAGE_INDENT "  ")
  set(ABSL_ENABLE_INSTALL ON)
  set(ABSL_USE_SYSTEM_INCLUDES ON)
  set(ABSL_PROPAGATE_CXX_STD ON)
  set(ABSL_BUILD_TESTING OFF)
  FetchContent_Declare(
    absl
    GIT_REPOSITORY "https://github.com/abseil/abseil-cpp.git"
    GIT_TAG "20240722.0"
    GIT_SHALLOW TRUE
    PATCH_COMMAND git apply --ignore-whitespace "${CMAKE_CURRENT_LIST_DIR}/../../patches/abseil-cpp-20240722.0.patch"
  )
  FetchContent_MakeAvailable(absl)
  list(POP_BACK CMAKE_MESSAGE_INDENT)
  message(CHECK_PASS "fetched")
endif()

###############
##  TESTING  ##
###############

# ##############################################################################
# RE2
# ##############################################################################
if(BUILD_re2)
  message(CHECK_START "Fetching re2")
  list(APPEND CMAKE_MESSAGE_INDENT "  ")
  set(RE2_BUILD_TESTING OFF)
  FetchContent_Declare(
    re2
    GIT_REPOSITORY "https://github.com/google/re2.git"
    GIT_TAG "2024-04-01"
    GIT_SHALLOW TRUE
    PATCH_COMMAND git apply --ignore-whitespace "${CMAKE_CURRENT_LIST_DIR}/../../patches/re2-2024-04-01.patch"
  )
  FetchContent_MakeAvailable(re2)
  list(POP_BACK CMAKE_MESSAGE_INDENT)
  message(CHECK_PASS "fetched")
endif()

# ##############################################################################
# GOOGLETEST
# ##############################################################################
if(BUILD_googletest)
  message(CHECK_START "Fetching googletest")
  list(APPEND CMAKE_MESSAGE_INDENT "  ")
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
    GIT_SHALLOW TRUE
    PATCH_COMMAND git apply --ignore-whitespace
    "${CMAKE_CURRENT_LIST_DIR}/../../patches/googletest-v1.15.2.patch"
    #PATCH_COMMAND git apply --ignore-whitespace ""
  )
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  set(INSTALL_GTEST OFF)
  set(GTEST_HAS_ABSL ON)
  if(WIN32)
    set(BUILD_SHARED_LIBS OFF)
  endif()
  FetchContent_MakeAvailable(googletest)
  if(WIN32)
    set(BUILD_SHARED_LIBS ON)
  endif()
  list(POP_BACK CMAKE_MESSAGE_INDENT)
  message(CHECK_PASS "fetched")
endif()
