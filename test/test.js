/**
 * XadillaX created at 2015-09-11 12:40:44 With ♥
 *
 * Copyright (c) 2015 Souche.com, all rights
 * reserved.
 */
require("should");
var bling = require("../");

describe("hash algorithm tests", function() {
    var words = [];
    var algorithms = [ "BKDR", "AP", "DJB", "JS", "RS", "SDBM", "PJW", "ELF" ];

    before(function() {
        var fs = require("fs");
        var str = fs.readFileSync(__dirname + "/resources/words.txt", { encoding: "utf8" });
        var temp = str.split("\n");
        for(var i = 0; i < temp.length; i++) {
            if(!temp[i]) continue;
            var line = temp[i].split(" ");
            for(var j = 0; j < line.length; j++) {
                if(!line[j]) continue;
                words.push(line[j]);
            }
        }
    });

    var getProcesser = function(name) {
        name = name.toLowerCase();

        return function() {
            var res = [];
            for(var i = 0; i < words.length; i++) {
                res.push(bling[name](words[i]));
            }

            // var fs = require("fs");
            // fs.writeFileSync(__dirname + "/resources/" + name + ".txt", res.join("\n"), {
            //     encoding: "utf8"
            // });
            
            var fs = require("fs");
            var std = fs.readFileSync(__dirname + "/resources/" + name + ".txt", {
                encoding: "utf8"
            });

            res.join("\n").should.be.eql(std);
        };
    };

    for(var i = 0; i < algorithms.length; i++) {
        it(algorithms[i] + " Hash", getProcesser(algorithms[i]));
    }
});
