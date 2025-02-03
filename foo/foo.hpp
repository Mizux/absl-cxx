#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include "absl/flags/declare.h"
#include "absl/strings/string_view.h"
#include "absl/status/status.h"
#include "absl/time/time.h"


#if defined(_MSC_VER) && defined(FOO_BUILD_DLL)
// Annoying stuff for windows -- makes sure clients can import these functions
#if defined(FOO_EXPORT)
#define FOO_DLL __declspec(dllexport)
#else
#define FOO_DLL __declspec(dllimport)
#endif  // defined(FOO_EXPORT)
#endif  // _MSC_VER && FOO_BUILD_DLL

#ifndef FOO_DLL
#define FOO_DLL
#endif

// The ABSL_DECLARE_DLL_FLAG(dll, type, name) macro expands to:
//   dll extern absl::Flag<type> FLAGS_name;
#define ABSL_DECLARE_DLL_FLAG(dll, type, name) ABSL_DECLARE_DLL_FLAG_INTERNAL(dll, type, name)

// Internal implementation of ABSL_DECLARE_FLAG to allow macro expansion of its
// arguments. Clients must use ABSL_DECLARE_FLAG instead.
#define ABSL_DECLARE_DLL_FLAG_INTERNAL(dll, type, name)      \
  dll extern absl::Flag<type> FLAGS_##name;                  \
  namespace absl /* block flags in namespaces */ {}          \
  /* second redeclaration is to allow applying attributes */ \
  dll extern absl::Flag<type> FLAGS_##name

#if 1
#pragma message("warning: Using ABSL_DECLARE_DLL_FLAG!")
ABSL_DECLARE_DLL_FLAG(FOO_DLL, bool, foo_bool);
ABSL_DECLARE_DLL_FLAG(FOO_DLL, int, foo_int);
ABSL_DECLARE_DLL_FLAG(FOO_DLL, int64_t, foo_long_int);
ABSL_DECLARE_DLL_FLAG(FOO_DLL, std::string, foo_string);
#elif 0
#pragma message("warning: Suppose ABSL_DECLARE_FLAG support it!")
FOO_DLL ABSL_DECLARE_FLAG(bool, foo_bool);
FOO_DLL ABSL_DECLARE_FLAG(int, foo_int);
FOO_DLL ABSL_DECLARE_FLAG(int64_t, foo_long_int);
FOO_DLL ABSL_DECLARE_FLAG(std::string, foo_string);
#else
#pragma message("warning: NO FOO_DLL support!")
ABSL_DECLARE_FLAG(bool, foo_bool);
ABSL_DECLARE_FLAG(int, foo_int);
ABSL_DECLARE_FLAG(int64_t, foo_long_int);
ABSL_DECLARE_FLAG(std::string, foo_string);
#endif
//! @namespace foo The `foo` namespace
namespace foo {

//! @defgroup AbslFunction Abseil function usage.
//! @{
//! @brief Abseil function in foo namespace.
absl::Status abslFunction(absl::string_view string);

absl::Duration MakeDuration(double secs);
absl::Duration MakeInfiniteDuration();
bool IsInfiniteDuration(const absl::Duration& duration);
bool CheckDuration(const absl::Duration& duration, double secs);
absl::Time MakeTime(double secs);
bool CheckDatetime(const absl::Time& datetime, double secs);

//absl::Status ReturnStatus();
absl::Status ReturnStatus(absl::StatusCode code, absl::string_view text = "");
//! @}

//! @defgroup FreeFunction Free function usage.
//! @{
/*! @brief Free function in foo namespace.
 * @param level Scope level.*/
void freeFunction(int level);
/*! @brief Free function in foo namespace.
 * @param level Scope level.*/
void freeFunction(int64_t level);
//! @}

//! @defgroup StringVector Vector of String usage.
//! @{
/*! @brief Test returning a vector of string.
 * @param level Scope level.
 * @return A vector of string.*/
std::vector<std::string> stringVectorOutput(int level);
/*! @brief Test using a vector of string passed by value.
 * @param data Input data.
 * @return The size of the data vector.*/
int stringVectorInput(std::vector<std::string> data);
/*! @brief Test using a vector of string passed by const ref.
 * @param data Input data.
 * @return The size of the data vector.*/
int stringVectorRefInput(const std::vector<std::string>& data);
//! @}

//! @defgroup StringJaggedArray Vector of Vector of String usage.
//! @{
/*! @brief Test returning a jagged array of string.
 * @param level Scope level.
 * @return A jagged array of string.*/
std::vector<std::vector<std::string>> stringJaggedArrayOutput(int level);
/*! @brief Test using a jagged array of string passed by value.
 * @param data Input data.
 * @return The size of the data outer vector.*/
int stringJaggedArrayInput(std::vector<std::vector<std::string>> data);
/*! @brief Test using a jagged array of string passed by const ref.
 * @param data Input data.
 * @return The size of the data outer vector.*/
int stringJaggedArrayRefInput(const std::vector<std::vector<std::string>>& data);
//! @}

//! @defgroup PairVector Vector of Pair usage.
//! @{
/*! @brief Test returning a vector of pair.
 * @param level Scope level.
 * @return A vector of pair.*/
std::vector<std::pair<int, int>> pairVectorOutput(int level);
/*! @brief Test using a vector of pair passed by value.
 * @param data Input data.
 * @return The size of the data vector.*/
int pairVectorInput(std::vector<std::pair<int, int>> data);
/*! @brief Test using a vector of pair passed by const ref.
 * @param data Input data.
 * @return The size of the data vector.*/
int pairVectorRefInput(const std::vector<std::pair<int, int>>& data);
//! @}

//! @defgroup PairJaggedArray Jagged array of Pair<int, int> usage.
//! @{
/*! @brief Test returning a jagged array of pair.
 * @param level Scope level.
 * @return A jagged array of pair.*/
std::vector<std::vector<std::pair<int, int>>> pairJaggedArrayOutput(int level);
/*! @brief Test using a jagged array of pair passed by value.
 * @param data Input data.
 * @return The size of the data outer vector.*/
int pairJaggedArrayInput(std::vector<std::vector<std::pair<int, int>>> data);
/*! @brief Test using a jagged of pair passed by const ref.
 * @param data Input data.
 * @return The size of the data outer vector.*/
int pairJaggedArrayRefInput(const std::vector<std::vector<std::pair<int, int>>>& data);
//! @}

//! @brief Class Foo.
class Foo {
 public:
  //! @defgroup StaticMembers Static members
  //! @{

  /*! @brief Static method of Foo class.
   * @param[in] level Scope level.*/
  static void staticFunction(int level);

  /*! @brief Static method of Foo class.
   * @param[in] level Scope level.*/
  static void staticFunction(int64_t level);

  //! @}

  //! @defgroup IntegerMembers Integer members
  //! @{

  /*! @brief Method (getter) of Foo class.
   * @return A member value.*/
  int getInt() const;
  /*! @brief Method (setter) of Foo class.
   * @param[in] input A member value.*/
  void setInt(int input);

  //! @}

  //! @defgroup Int64Members Long Integer members
  //! @{

  /*! @brief Method (getter) of Foo class.
   * @return A member value.*/
  int64_t getInt64() const;
  /*! @brief Method (setter) of Foo class.
   * @param[in] input A member value.*/
  void setInt64(int64_t input);

  //! @}

  //! @brief Print object for debug.
  std::string operator()() const;

 private:
  int     _intValue   = 0;
  int64_t _int64Value = 0;
};
} // namespace foo
