package(default_visibility = ["//visibility:public"])

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(
        ["*.h"],
        exclude = ["WeaselUI.h"],
    ),
    defines = [
        "UNICODE",
        "_UNICODE",
        "WIN32",
        "_LIB",
    ],
    deps = [
        ":interface",
        "//third_party/wtl",
    ],
)

cc_library(
    name = "interface",
    hdrs = ["WeaselUI.h"],
    deps = [
        "//common:weasel_common",
    ],
)
