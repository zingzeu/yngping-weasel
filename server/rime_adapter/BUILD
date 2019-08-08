cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.h"]),
    defines = [
        "WIN32",
        "UNICODE",
        "_LIB",
        "BOOST_ALL_NO_LIB",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//common:str_algo",
        "//common:version",
        "//include/rime:interface",
        "//ipc:interface",
        "//ui:interface",
        "@boost//:archive",
        "@boost//:interprocess",
        "@boost//:thread",
    ],
)
