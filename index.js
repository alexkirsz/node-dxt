var dxt = require('./build/Release/dxt');

var flags = {
  kDxt1: 1 << 0,
  kDxt3: 1 << 1,
  kDxt5: 1 << 2,
  kColourIterativeClusterFit: 1 << 8,
  kColourClusterFit: 1 << 3,
  kColourRangeFit: 1 << 4,
  kColourMetricPerceptual: 1 << 5,
  kColourMetricUniform: 1 << 6,
  kWeightColourByAlpha: 1 << 7
};

exports.compress = function compress(input, width, height, flags) {
  if (!Buffer.isBuffer(input))
    throw new Error("Argument 1 of dxt.compress() (input) must be a buffer");
  if (typeof width !== 'number')
    throw new Error("Argument 2 of dxt.compress() (width) must be a number");
  if (typeof height !== 'number')
    throw new Error("Argument 3 of dxt.compress() (height) must be a number");
  if (typeof flags !== 'number' && typeof flags !== 'undefined')
    throw new Error("Argument 4 of dxt.compress() (flags) should be a number or undefined");

  return dxt.compress(input, width, height, flags);
};

exports.decompress = function decompress(input, width, height, flags) {
  if (!Buffer.isBuffer(input))
    throw new Error("Argument 1 of dxt.compress() (input) must be a buffer");
  if (typeof width !== 'number')
    throw new Error("Argument 2 of dxt.compress() (width) must be a number");
  if (typeof height !== 'number')
    throw new Error("Argument 3 of dxt.compress() (height) must be a number");
  if (typeof flags !== 'number' && typeof flags !== 'undefined')
    throw new Error("Argument 4 of dxt.compress() (flags) should be a number or undefined");

  return dxt.decompress(input, width, height, flags);
};

for (var key in flags) {
  exports[key] = flags[key];
}
