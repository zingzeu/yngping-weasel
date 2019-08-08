# WinXP compatitable VersionHelpers header
cc_library(
    name = "version_helpers_xp",
    hdrs = ["VersionHelpers.hpp"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "weasel_common",
    hdrs = ["WeaselCommon.h"],
    defines = [
        "BOOST_ALL_NO_LIB",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@boost//:serialization",
    ],
)

cc_library(
    name = "resource",
    hdrs = ["resource.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "str_algo",
    hdrs = ["StringAlgorithm.hpp"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "response_parser",
    hdrs = ["ResponseParser.h"],
    visibility = ["//visibility:public"],
    deps = [
        ":weasel_common",
    ],
)

cc_library(
    name = "version",
    hdrs = ["WeaselVersion.h"],
    visibility = ["//visibility:public"],
)
