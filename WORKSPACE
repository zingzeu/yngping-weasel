# Workaround for deprecated `git_repository` command
# On Windows, make sure the `BAZEL_SH` is set, otherwise git_repository
# will fail. See: https://github.com/bazelbuild/bazel/issues/6339
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# Boost
#git_repository(
#    name = "com_github_nelhage_rules_boost",
#    commit = "eafab11dbd1d4cd1151f8407bd6ed81d1240d122",
#    remote = "https://github.com/nelhage/rules_boost",
#)

local_repository(
    name = "com_github_nelhage_rules_boost",
    path = "rules_boost",
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")

boost_deps()

# 32-bit cross tool
#git_repository(
#    name = "windows_cc_config_init",
#    commit = "5000000d5dd1fc69df79c33ffe47bed27ae47684",
#    remote = "https://github.com/excitoon/bazel-win32-toolchain",
#)

local_repository(
    name = "windows_cc_config_init",
    path = "win32-toolchain",
)

load("@windows_cc_config_init//:windows_toolchain.bzl", "windows_toolchain")

windows_toolchain(
    name = "windows_cc_config",
)
