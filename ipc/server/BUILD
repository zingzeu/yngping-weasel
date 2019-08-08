cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.h"]),
    defines = [
        "WIN32",
        "_LIB",
        "UNICODE",
        "BOOST_ALL_NO_LIB",
    ],
    visibility = [
        "//server:__subpackages__",
    ],
    deps = [
        "//common:resource",
        "//ipc:interface",
        "//ipc:pipe_channel",
        "//third_party/wtl",
        "@boost//:thread",
    ],
)
