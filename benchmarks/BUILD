load("@rules_python//python:defs.bzl", "py_binary", "py_library", "py_test")

licenses(["notice"])  # Apache 2

py_binary(
    name = "benchmarks",
    srcs = [
        "static_benchmarks.py",
    ],
    main = "static_benchmarks.py",
    srcs_version = "PY2AND3",
    deps = [
        ":benchmarks_envoy_proxy_lib",
        ":utilities_lib",
        "//test/integration:integration_test_base_lean",
    ],
)

py_test(
    name = "test_benchmarks",
    srcs = [
        "static_benchmarks.py",
        "test/test_discovery.py",
    ],
    main = "static_benchmarks.py",
    srcs_version = "PY2AND3",
    deps = [
        ":benchmarks_envoy_proxy_lib",
        ":utilities_lib",
        "//test/integration:integration_test_base",
    ],
)

py_library(
    name = "benchmarks_envoy_proxy_lib",
    srcs = [
        "envoy_proxy.py",
    ],
    data = [
        "configurations/envoy_proxy.yaml",
    ],
    srcs_version = "PY2AND3",
    deps = [
        "@rules_python//python/runfiles",
    ],
)

py_library(
    name = "benchmarks_dynamic_envoy_proxy_lib",
    srcs = [
        "dynamic_config_envoy_proxy.py",
        "envoy_proxy.py",
    ],
    data = [
        "configurations/dynamic_resources.yaml",
        "configurations/dynamic_resources_eds.yaml",
        "configurations/lds.yaml",
        "configurations/request_source_five_clusters.json",
    ],
    srcs_version = "PY2AND3",
    deps = [
        "//api/configuration:cluster_config_manager_py_proto",
        "@rules_python//python/runfiles",
    ],
)

py_test(
    name = "test_dynamic_benchmarks",
    srcs = [
        "dynamic_benchmarks.py",
        "dynamic_test/test_cds_churn_with_traffic.py",
        "dynamic_test/test_eds_churn_with_traffic.py",
    ],
    main = "dynamic_benchmarks.py",
    srcs_version = "PY2AND3",
    deps = [
        ":benchmarks_dynamic_envoy_proxy_lib",
        ":utilities_lib",
        "//dynamic_config:dynamic_config_server",
        "//test/integration:integration_test_base",
    ],
)

py_binary(
    name = "dynamic_benchmarks",
    srcs = [
        "dynamic_benchmarks.py",
    ],
    main = "dynamic_benchmarks.py",
    srcs_version = "PY2AND3",
    deps = [
        ":benchmarks_dynamic_envoy_proxy_lib",
        ":utilities_lib",
        "//dynamic_config:dynamic_config_server",
        "//test/integration:integration_test_base_lean",
    ],
)

py_library(
    name = "utilities_lib",
    srcs = [
        "utilities.py",
    ],
    data = [
        "templates/simple_plot.html",
    ],
    srcs_version = "PY2AND3",
    deps = [
        "@rules_python//python/runfiles",
    ],
)
