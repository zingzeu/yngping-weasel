cc_library(
    name = "interface",
    hdrs = ["WeaselIPC.h"],
    visibility = [
        "//visibility:public",
    ],
    deps = [
        "//common:weasel_common",
        "//include:util",
    ],
)

cc_library(
    name = "pipe_channel",
    hdrs = ["PipeChannel.h"],
    defines = [
        "BOOST_ALL_NO_LIB",
    ],
    visibility = [
        "//ipc:__subpackages__",
    ],
    deps = [
        "@boost//:interprocess",
        "@boost//:thread",
    ],
)
