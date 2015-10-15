{

  "targets": [
    {
      "target_name": "dxt",
      "sources": [
        "src/squish/alpha.cpp",
        "src/squish/clusterfit.cpp",
        "src/squish/colourblock.cpp",
        "src/squish/colourfit.cpp",
        "src/squish/colourset.cpp",
        "src/squish/maths.cpp",
        "src/squish/rangefit.cpp",
        "src/squish/singlecolourfit.cpp",
        "src/squish/squish.cpp",
        "src/dxt.cc"
      ],
      "include_dirs": ["<!(node -e \"require('nan')\")","src/squish"],
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "conditions": [
        ["OS==\"mac\"", {
          "xcode_settings": {
            "GCC_ENABLE_CPP_EXCEPTIONS": "YES"
          }
        }]
      ]
    }
  ]
}
