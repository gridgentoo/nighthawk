load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")
load("@envoy_api//bazel:api_build_system.bzl", "api_cc_py_proto_library")

licenses(["notice"])  # Apache 2

api_cc_py_proto_library(
    name = "base",
    srcs = [
        "options.proto",
        "output.proto",
        "service.proto",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@envoy_api//envoy/config/core/v3:pkg",
        "@envoy_api//envoy/config/metrics/v3:pkg",
        "@envoy_api//envoy/extensions/transport_sockets/tls/v3:pkg",
    ],
)

cc_grpc_library(
    name = "grpc_service_lib",
    srcs = [
        ":base",
    ],
    generate_mocks = True,
    grpc_only = True,
    proto_only = False,
    use_external = False,
    visibility = ["//visibility:public"],
    deps = [
        ":base_cc_proto",
    ],
)
