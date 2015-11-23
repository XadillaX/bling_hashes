/**
 * XadillaX created at 2015-09-11 12:31:52 With ♥
 *
 * Copyright (c) 2015 Souche.com, all rights
 * reserved.
 */
var bling = require("./build/Release/bling");
var Long = require("long");

/**
 * bkdr
 * @param {String} str the string will be hashed
 * @return {Number} the hash value
 */
exports.bkdr = function(str) {
    return bling.calcHash("BKDR", str);
};

/**
 * ap
 * @param {String} str the string will be hashed
 * @return {Number} the hash value
 */
exports.ap = function(str) {
    return bling.calcHash("AP", str);
};

/**
 * djb
 * @param {String} str the string will be hashed
 * @return {Number} the hash value
 */
exports.djb = function(str) {
    return bling.calcHash("DJB", str);
};

/**
 * js
 * @param {String} str the string will be hashed
 * @return {Number} the hash value
 */
exports.js = function(str) {
    return bling.calcHash("JS", str);
};

/**
 * rs
 * @param {String} str the string will be hashed
 * @return {Number} the hash value
 */
exports.rs = function(str) {
    return bling.calcHash("RS", str);
};

/**
 * sdb
 * @param {String} str the string will be hashed
 * @return {Number} the hash value
 */
exports.sdbm = function(str) {
    return bling.calcHash("SDBM", str);
};

/**
 * pjw
 * @param {String} str the string will be hashed
 * @return {Number} the hash value
 */
exports.pjw = function(str) {
    return bling.calcHash("PJW", str);
};

/**
 * elf
 * @param {String} str the string will be hashed
 * @return {Number} the hash value
 */
exports.elf = function(str) {
    return bling.calcHash("ELF", str);
};

/**
 * city32
 * @param {String} str the string will be hashed
 * @return {Number} the hash value
 */
exports.city32 = function(str) {
    return bling.cityHash32(str);
};

/**
 * city64
 * @param {String} str the string will be hashed
 * @return {Long} the hash value
 */
exports.city64 = function(str) {
    var _int64 = bling.cityHash64(str);
    _int64 = new Long(_int64.readInt32LE(0), _int64.readInt32LE(4), true);
    return _int64;
};
