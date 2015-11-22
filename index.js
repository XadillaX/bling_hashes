/**
 * XadillaX created at 2015-09-11 12:31:52 With ♥
 *
 * Copyright (c) 2015 Souche.com, all rights
 * reserved.
 */
var bling = require("./build/Release/bling");

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

exports.city32 = function(str) {
    return bling.cityHash32(str);
};
