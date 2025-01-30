#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "absl/base/log_severity.h"
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/flags/usage.h"
#include "absl/log/globals.h"
#include "absl/log/initialize.h"
#include "absl/log/log.h"
#include "absl/strings/str_join.h"
#include "foo/foo.hpp"

void* kVar = [] {
  std::cerr << "kApp\n";
  return nullptr;
}();


int main(int argc, char* argv[]) {
  absl::InitializeLog();
  absl::SetProgramUsageMessage("app");
  absl::EnableLogPrefix(false);
  absl::SetStderrThreshold(absl::LogSeverity::kInfo);
  absl::ParseCommandLine(argc, argv);
  {
    const std::vector<std::string> v = {"foo","bar","baz"};
    std::string s = absl::StrJoin(v, "-");
    LOG(INFO) << "Joined string: " << s << "\n";
  }

  foo::freeFunction(int{0});
  LOG(INFO) << std::endl;
  foo::freeFunction(int64_t{1});
  LOG(INFO) << std::endl;

  foo::Foo::staticFunction(int{2});
  LOG(INFO) << std::endl;
  foo::Foo::staticFunction(int64_t{3});
  LOG(INFO) << std::endl;

  foo::Foo f;
  f.setInt(13);
  LOG(INFO) << std::to_string(f.getInt()) << std::endl;

  f.setInt64(int64_t{31});
  LOG(INFO) << std::to_string(f.getInt64()) << std::endl;

  LOG(INFO) << f() << std::endl;

  LOG(INFO) << absl::GetFlag(FLAGS_foo_bool) << std::endl;
  LOG(INFO) << absl::GetFlag(FLAGS_foo_int) << std::endl;
  LOG(INFO) << absl::GetFlag(FLAGS_foo_long_int) << std::endl;
  LOG(INFO) << absl::GetFlag(FLAGS_foo_string) << std::endl;
  return 0;
}
