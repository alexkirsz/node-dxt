var dxt = require('../');
var assert = require('assert');

describe('dxt', function() {
  it('should export compress that returns a buffer', function() {
    assert.equal(typeof dxt.compress(new Buffer(0), 0, 0), 'object');
  });
  it('should export decompress that returns a buffer', function() {
    assert.equal(typeof dxt.decompress(new Buffer(0), 0, 0), 'object');
  });
  /*
  it('should be able to decompress a dds file', function(done) {
    var fs = require('fs');
    fs.readFile('test/test.dds', function(err, data) {
      var bitmapData = dxt.decompress(data, 1024, 1024, dxt.kDxt5);
      fs.open('test/test_out.bmp', 'w', function(err, fd) {
         function dec2hex(i) {
            return (i+0x100000000).toString(16).substr(-8).toUpperCase().match(/../g).reverse().join('');
         }
         //Write bmp header
        var headerBuffer = new Buffer("424D"+dec2hex(((1024*1024*32)/8)+54)+"0000"+"0000"+dec2hex(54)+dec2hex(40)+dec2hex(1024)+dec2hex(1024)+"0100"+"2000"+"00000000"+dec2hex(1024*1024*32/8)+"00000000000000000000000000000000", 'hex');
        fs.writeSync(fd, headerBuffer, 0, 54);
        fs.writeSync(fd, bitmapData, 0, bitmapData.length, 54);
        fs.closeSync(fd);
        done();
      });
    });
  });
  */
});
