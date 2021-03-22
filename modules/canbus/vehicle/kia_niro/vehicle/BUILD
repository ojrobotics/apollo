load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "niro_jscmd",
    srcs = [
        "niro_jscmd.cc",
    ],

    deps = [
        "@oscc_synergy_project//core:oscc_lib",
        "@oscc_synergy_project//joy:joy_lib",
        # "@sdl2//:lib",
    ],

    includes = [
        "@oscc_synergy_project:core/include",
        "external/oscc_synergy_project/core/include",
        "@oscc_synergy_project:joy/include",
        "external/oscc_synergy_project/joy/include",
    ],

    copts = [
        "-Iexternal/oscc_synergy_project/core/include",
        "-Iexternal/oscc_synergy_project/joy/include",
        "-DKIA_NIRO",
        "-DVEHICLE=kia_niro",
    ],
)

cc_binary(
    name = "niro_jsdummy",
    srcs = [
        "niro_jsdummy.cc",
    ],

    deps = [
        "//cyber",
        "//modules_syn/oscc_jscmd/proto:oscc_cc_proto",
        "@oscc_synergy_project//core:oscc_lib",
        "@oscc_synergy_project//joy:joy_lib",
        # "@sdl2//:lib",
    ],

    includes = [
        "@oscc_synergy_project:core/include",
        "external/oscc_synergy_project/core/include",
        "@oscc_synergy_project:joy/include",
        "external/oscc_synergy_project/joy/include",
    ],

    copts = [
        "-Iexternal/oscc_synergy_project/core/include",
        "-Iexternal/oscc_synergy_project/joy/include",
        "-DKIA_NIRO",
        "-DVEHICLE=kia_niro",
    ],
)

cc_binary(
    name = "niro_streaming_status",
    srcs = [
        "niro_streaming_status.cc",
    ],

    deps = [
        "//cyber",
        "//modules/canbus/proto:kia_niro_cc_proto",
        "@oscc_synergy_project//core:oscc_lib",
        "@oscc_synergy_project//joy:joy_lib",
        # "@sdl2//:lib",
    ],

    includes = [
        "@oscc_synergy_project:core/include",
        "external/oscc_synergy_project/core/include",
        "@oscc_synergy_project:joy/include",
        "external/oscc_synergy_project/joy/include",
    ],

    copts = [
        "-Iexternal/oscc_synergy_project/core/include",
        "-Iexternal/oscc_synergy_project/joy/include",
        "-DKIA_NIRO",
        "-DVEHICLE=kia_niro",
    ],
)

cc_binary(
    name = "niro_listening_command",
    srcs = [
        "niro_listening_command.cc",
    ],

    deps = [
        "//cyber",
        "//modules/canbus/proto:kia_niro_cc_proto",
        "@oscc_synergy_project//core:oscc_lib",
        "@oscc_synergy_project//joy:joy_lib",
        # "@sdl2//:lib",
    ],

    includes = [
        "@oscc_synergy_project:core/include",
        "external/oscc_synergy_project/core/include",
        "@oscc_synergy_project:joy/include",
        "external/oscc_synergy_project/joy/include",
    ],

    copts = [
        "-Iexternal/oscc_synergy_project/core/include",
        "-Iexternal/oscc_synergy_project/joy/include",
        "-DKIA_NIRO",
        "-DVEHICLE=kia_niro",
    ],
)

cc_binary(
    name = "niro_status",
    srcs = [
        "niro_status.cc",
    ],

    deps = [
        "//cyber",
        "//modules_syn/oscc_jscmd/proto:oscc_cc_proto",
        "@oscc_synergy_project//core:oscc_lib",
        "@oscc_synergy_project//joy:joy_lib",
        # "@sdl2//:lib",
    ],

    includes = [
        "@oscc_synergy_project:core/include",
        "external/oscc_synergy_project/core/include",
        "@oscc_synergy_project:joy/include",
        "external/oscc_synergy_project/joy/include",
    ],

    copts = [
        "-Iexternal/oscc_synergy_project/core/include",
        "-Iexternal/oscc_synergy_project/joy/include",
        "-DKIA_NIRO",
        "-DVEHICLE=kia_niro",
    ],
)

# cc_binary(
#     name = "niro_status",
#     srcs = [
#         "oscc_niro_status.cc",
#         "commander.c",
#         "commander.h",
#         # "joystick.h",
#         # "joystick.c"
#     ],
#     # hdrs = [
#     # ],
#     deps = [
#         "//cyber",
#         "//modules/oscc_jscmd/oscc:oscc_lib",
#         "//modules/oscc_jscmd/proto:oscc_cc_proto",
#     ]
# )



cc_binary(
    name = "talker",
    srcs = ["talker.cc"],
    deps = [
        "//cyber",
        "//modules_syn/oscc_jscmd/proto:examples_cc_proto",
    ],
)

cc_binary(
    name = "listener",
    srcs = ["listener.cc"],
    deps = [
        "//cyber",
        "//modules/oscc_jscmd/proto:examples_cc_proto",
    ],
)

cc_binary(
    name = "paramserver",
    srcs = ["paramserver.cc"],
    deps = [
        "//cyber",
        "//cyber/parameter",
    ],
)

cc_binary(
    name = "service",
    srcs = ["service.cc"],
    deps = [
        "//cyber",
        "//modules/oscc_jscmd/proto:examples_cc_proto",
    ],
)

cc_binary(
    name = "record",
    srcs = ["record.cc"],
    deps = [
        "//cyber",
        "//cyber/proto:record_cc_proto",
    ],
)

cpplint()
