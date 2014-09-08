function processData(input) {
var max_n = 1000000
var sieve = []
var primes = []

for (var i = 0; i < 2    ; i++) sieve.push(false)
for (var i = 2; i < max_n; i++) sieve.push(true)

for (var i = 2; i < max_n; i++) {
    if (sieve[i]) {
        primes.push(i)
        for (var j = 2*i; j < max_n; j += i) {
            sieve[j] = false
        }
    }
}

function sum(lim) {
    var p = 0
    for (var i = 0; primes[i] <= lim; i++)
        p += primes[i]
    return p
}

var lines = input.split("\n")
var t = parseInt(lines[0])

for (var i = 1; i <= t; i++)
    console.log(sum(parseInt(lines[i])))

}

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});
