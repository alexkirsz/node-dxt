var nativeExtension = require('../');
var assert = require('assert');

describe('dxt', function() {
  it('should export compress that returns a buffer', function() {
    assert.equal(typeof nativeExtension.compress(new Buffer(0), 0, 0), 'object');
  });
  it('should export decompress that returns a buffer', function() {
    assert.equal(typeof nativeExtension.decompress(new Buffer(0), 0, 0), 'object');
  });
});
