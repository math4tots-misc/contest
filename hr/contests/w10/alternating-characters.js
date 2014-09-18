var input = ""

function group(xs) {
    var last = xs[0]
    var sizes = [ 0 ]
    for (var i = 1; i < xs.length; i++) {
        if (xs[i] === last)
            sizes[sizes.length - 1] += 1
        else {
            sizes.push(0)
            last = xs[i]
        }
    }
    return sizes
}

function solve() {
    var lines = input.
        split("\n").
        filter(function(s){return s.trim().length > 0})
    
    for (var i = 1; i < lines.length; i++) {
        var s = lines[i].trim()
        console.log(
            group(s.split("")).
                reduce(function (x,y) { return x + y}))
    }
    
}

process.stdin.setEncoding('ascii')
process.stdin.on('data', function(chunk) {if (chunk !== null) input += chunk})
process.stdin.on('end', function() { solve() })

