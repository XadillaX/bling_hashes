const bling = require('./index');

const testString = "Hello, Trae!";

console.log(`Testing with string: "${testString}"\n`);

// BKDR Hash
console.log(`BKDR Hash: ${bling.bkdr(testString)}`);

// AP Hash
console.log(`AP Hash:   ${bling.ap(testString)}`);

// CityHash 32
console.log(`CityHash32: ${bling.city32(testString)}`);

// CityHash 64
const city64 = bling.city64(testString);
console.log(`CityHash64: ${city64.toString()}`);

// CityHash 128
const city128 = bling.city128(testString);
console.log(`CityHash128: ${city128.toString()}`);
