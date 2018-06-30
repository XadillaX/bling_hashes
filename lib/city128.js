'use strict';

const BigNumber = require("big-number");
const Long = require("long");

const MAX_UINT64 = '18446744073709551616';

function City128Value(bufs) {
    this.bufs = bufs;
    this.longs = this.toLongArray();
    this.val = (new BigNumber(this.longs[0].toString()))
        .multiply(MAX_UINT64)
        .plus(this.longs[1].toString());
}

City128Value.prototype.toString = function toString() {
    return this.val.toString();
};

City128Value.prototype.toLongArray = function toBufferArray() {
    return this.bufs.map(r => new Long(r.readInt32LE(0), r.readInt32LE(4), true));
};

City128Value.prototype.toBuffers = function() {
    return [ Buffer.from(this.bufs[0]), Buffer.from(this.bufs[1]) ];
};

City128Value.toBigNumber() {
    return new BigNumber(this.toString());
};

module.exports = City128Value;
