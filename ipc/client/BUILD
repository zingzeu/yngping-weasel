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
        "//tsf:__subpackages__",
    ],
    deps = [
        "//common:response_parser",
        "//common:str_algo",
        "//include:util",
        "//ipc:interface",
        "//ipc:pipe_channel",
        "@boost//:archive",
        "@boost//:interprocess",
    ],
)
