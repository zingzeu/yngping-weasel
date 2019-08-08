# Win32 app
cc_binary(
    name = "win32",
    srcs = ["win32.cpp"],
    defines = [
        "UNICODE",
        "_UNICODE",
        "WIN32",
        "BOOST_ALL_NO_LIB",
    ],
    linkopts = ["/SUBSYSTEM:WINDOWS"],
    deps = [
        "//common:weasel_common",
        "//include:util",
        "//third_party/wtl",
        "//ui:lib",
        "@boost//:thread",
    ],
)

# Console app (Subsystem CONSOLE)
cc_binary(
    name = "console",
    srcs = ["console.cpp"],
    defines = [
        "UNICODE",
        "_UNICODE",
        "WIN32",
    ],
    deps = [
        "//ui:lib",
    ],
)
