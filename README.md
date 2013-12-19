node-dxt
========

Node.JS bindings for the squish DXT compression/decompression library.

```
$ npm install dxt
```

# dxt.compress(input, width, height [, flags])
Compress `input` buffer. Returns a buffer.

# dxt.decompress(input, width, height [, flags])
Decompress `input` buffer. Returns a buffer.

## flags
```
dxt.{
  // COMPRESSION/DECOMPRESSION METHODS
  kDxt1,
  kDxt3,
  kDxt5,

  // SUPPLEMENTARY COMPRESSION FLAGS
  kColourIterativeClusterFit, // Use a very slow but very high quality colour compressor.
  kColourClusterFit,          // Use a slow but high quality colour compressor (the default).
  kColourRangeFit,            // Use a fast but low quality colour compressor.

  kColourMetricPerceptual,    // Use a perceptual metric for colour error (the default).
  kColourMetricUniform,       // Use a uniform metric for colour error.

  kWeightColourByAlpha        // Weight the colour by alpha during cluster fit (disabled by default).
}
```
