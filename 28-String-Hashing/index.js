console.log('connected');

/**
 * Computes a hashed integer value given a string input
 * @param {The string to compute the hash value for} toHash 
 * @return The integer value computed
 */
function hashString(toHash){
    const p = 51;
    const m = 1e9 + 9;
    const a_value = 'a'.charCodeAt(0);
    var hashValue = 0;
    var powP = 1;

    for (let i = 0; i < toHash.length; i ++){
        var c = toHash.charCodeAt(i);

        hashValue = (hashValue + (c - a_value + 1) * powP) % m;
        powP = (powP * p) % m;
    }

    return hashValue;
}

console.log( 'The hash value is : ' , hashString('this is a test string')) ;
console.log( 'The hash value is : ' , hashString('this is a test strina')) ;
console.log( 'The hash value is : ' , hashString('this is a test string')) ;
