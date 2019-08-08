cc_binary(
    name = "app",
    srcs = [
        "WeaselServer.cpp",
        "WeaselServer.h",
        "WeaselServerApp.cpp",
        "WeaselServerApp.h",
        "WeaselService.cpp",
        "WeaselService.h",
        "WeaselTrayIcon.cpp",
        "WeaselTrayIcon.h",
        "stdafx.cpp",
        "stdafx.h",
    ],
    defines = [
        "WIN32",
        "_WINDOWS",
        "STRICT",
        "UNICODE",
        "BOOST_ALL_NO_LIB",  # Avoid Boost autolink messing with Bazel's generated .lib filenames.
        "BOOST_THREAD_USE_LIB",
        "BOOST_WIN32_THREAD",
    ],
    linkopts = ["/SUBSYSTEM:WINDOWS"],
    deps = [
        "//common:resource",
        "//ipc:interface",
        "//ipc/client:lib",
        "//ipc/server:lib",
        "//prebuilt/librime:x86",
        "//server/rime_adapter:lib",
        "//third_party/system_tray:lib",
        "//third_party/wtl",
        "//ui:interface",
        "//ui:lib",
    ],
)

genrule(
    name = "resource",
    srcs = [
        "WeaselServer.rc",
        "//resource:en.ico",
        "//resource:reload.ico",
        "//resource:weasel.ico",
        "//resource:zh.ico",
        "//common:resource",
    ],
    outs = [
        "WeaselServer.res",
    ],
    cmd = "/c/Program\ Files\ \(x86\)/Windows\ Kits/10/bin/10.0.17763.0/x86/rc.exe server/WeaselServer.rc",
)
