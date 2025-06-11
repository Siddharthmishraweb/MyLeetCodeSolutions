function maxDifference(s, k) {
    const n = s.length;
    const pre = Array.from({ length: 5 }, () => Array(n).fill(0));
    const nextRight = Array.from({ length: 5 }, () => Array(n).fill(n));

    for (let digit = 0; digit < 5; digit++) {
        for (let i = 0; i < n; i++) {
            const num = parseInt(s[i]);
            pre[digit][i] = num === digit ? 1 : 0;
            if (i > 0) pre[digit][i] += pre[digit][i - 1];
        }
        for (let i = n - 1; i >= 0; i--) {
            const num = parseInt(s[i]);
            if (i < n - 1) nextRight[digit][i] = nextRight[digit][i + 1];
            if (num === digit) nextRight[digit][i] = i;
        }
    }

    let result = -Infinity;

    function checkPair(oddDigit, evenDigit) {
        const suffix = Array.from({ length: 2 }, () =>
            Array.from({ length: 2 }, () => Array(n).fill(-Infinity))
        );

        for (let end = 0; end < n; end++) {
            const oddFreq = pre[oddDigit][end];
            const evenFreq = pre[evenDigit][end];
            const oddParity = oddFreq % 2;
            const evenParity = evenFreq % 2;

            if (oddFreq > 0 && evenFreq > 0) {
                suffix[oddParity][evenParity][end] = oddFreq - evenFreq;
            }
        }

        for (let op = 0; op < 2; op++) {
            for (let ep = 0; ep < 2; ep++) {
                for (let i = n - 2; i >= 0; i--) {
                    suffix[op][ep][i] = Math.max(suffix[op][ep][i], suffix[op][ep][i + 1]);
                }
            }
        }

        for (let start = 0; start < n; start++) {
            const minEnd = start + k - 1;
            if (minEnd >= n) break;

            const oddBelow = start === 0 ? 0 : pre[oddDigit][start - 1];
            const evenBelow = start === 0 ? 0 : pre[evenDigit][start - 1];

            const goodOddParity = (oddBelow + 1) % 2;
            const goodEvenParity = evenBelow % 2;

            const queryStart = Math.max(minEnd, nextRight[oddDigit][start], nextRight[evenDigit][start]);
            if (queryStart >= n) continue;

            const val = suffix[goodOddParity][goodEvenParity][queryStart];
            if (val === -Infinity) continue;

            result = Math.max(result, val - oddBelow + evenBelow);
        }
    }

    for (let i = 0; i <= 4; i++) {
        for (let j = 0; j <= 4; j++) {
            if (i !== j) checkPair(i, j);
        }
    }

    return result === -Infinity ? 0 : result;
}