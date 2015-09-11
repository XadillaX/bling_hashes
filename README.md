# Bling Hashes

String hash algorithms for node.js.

## Installation

```shell
$ npm install --save bling-hashes
```

## Introduce

There are 8 algorithms so far.

  * [BKDRHash](http://www.partow.net/programming/hashfunctions/#BKDRHashFunction)
  * [APHash](http://www.partow.net/programming/hashfunctions/#APHashFunction)
  * [DJBHash](http://www.partow.net/programming/hashfunctions/#DJBHashFunction)
  * [JSHash](http://www.partow.net/programming/hashfunctions/#JSHashFunction)
  * [RSHash](http://www.partow.net/programming/hashfunctions/#RSHashFunction)
  * [SDBMHash](http://www.partow.net/programming/hashfunctions/#SDBMHashFunction)
  * [PJWHash](http://www.partow.net/programming/hashfunctions/#PJWHashFunction)
  * [ELFHash](http://www.partow.net/programming/hashfunctions/#ELFHashFunction)

The benchmark, performance and implementation can be referenced [here (各种字符串Hash函数比较)](https://www.byvoid.com/blog/string-hash-compare/).

## Usage

First you should require this package.

```javascript
var bling = require("bling-hashes");
```

And then you can pass any string to functions (the same name as algorithms, in lowercase).

Eg.

```javascript
var hash = bling.bkdr("Hello world!"); ///< 501511565
```

## Contribution

Thanks to [ByVoid](https://github.com/byvoid). The C++ implementation code was copied from his blog.

You're welcome to make pull requests.

「雖然我覺得不怎麼可能有人會關注我」
