/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var out = [];
    for(let i=0;i<arr.length;i++){
        if(fn(arr[i],i)){
            out.push(arr[i]);
        }
    }
    return out;
};