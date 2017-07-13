function getIsPrime(untilNum) {
	var isPrime = new Array(untilNum+1);
    isPrime[1] = false;
	isPrime[2] = true;

	// nest
	for (var curPrime = 2; curPrime <= untilNum; curPrime++) {
		if (isPrime[curPrime] === false) {
			continue;
		}
        
        isPrime[curPrime] = true;

		for (var multiple = curPrime*2; multiple <= untilNum; multiple += curPrime) {
			isPrime[multiple] = false;
		}
	}

	return isPrime;
}

function countPrimes(isPrime, start, end) {
	return isPrime.slice(start, end+1).reduce(function(count, i) {
		return count + (i? 1: 0);
	}, 0);
}

(function() {
	var input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
	var isPrime = getIsPrime(123456*2);

	for (var i = 0; i < input.length; i++) {
		var n = parseInt(input[i]);
        if(n==0)
            break;
		console.log(countPrimes(isPrime, n+1, 2*n));
	}
})();