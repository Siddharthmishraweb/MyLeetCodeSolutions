/**
 * @param {number} num
 * @return {number}
 */
var maxDiff = function(num) {
    let s = num.toString();
    let d1 = [...s].find(c => c !== '9');
    let a = d1 ? s.replaceAll(d1, '9') : s;
    let b = s;
    if (s[0] !== '1') {
        b = s.replaceAll(s[0], '1');
    } else {
        for (let i = 1; i < s.length; i++) {
            if (s[i] !== '0' && s[i] !== '1') {
                b = s.replaceAll(s[i], '0');
                break;
            }
        }
    }
    return parseInt(a) - parseInt(b);
};

