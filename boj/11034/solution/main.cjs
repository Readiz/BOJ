function solution_11034(scanner) {
    let [a,b,c] = scanner.readLine().split(' ').map(Number);
    let ans = 0;
    while (true) {
        if (b < a) [a,b]=[b,a];
        if (c < b) [b,c]=[c,b];
        let d1 = b - a;
        let d2 = c - b;
        if (d1 < d2) a = b + 1;
        else c = b - 1;
        if (a == b || b == c || c == a) break;
        ans++;
    }
    return ans;
}

function solution(scanner) {
    const result = [];
    try {
        while(true) {
            result.push(solution_11034(scanner));
        }
    } catch (e) {}
    return result.join('\n');
}

/////////////////////////////////////////////////////////////////////////////////
// Readiz BOJ JS Util Start
/////////////////////////////////////////////////////////////////////////////////
const scanner = {
    readInt: () => {
        return parseInt(__lineDB[__lineIdx++], 10);
    },
    readLine: () => {
        return __lineDB[__lineIdx++];
    }
};
let __lineDB = [];
let __lineIdx = 0;
const isDebug = process.argv[2] === 'readizDebug';
if (!isDebug) {
    global.console = {
        log: () => {},
        warn: () => {},
        info: () => {},
        debug: () => {},
        error: () => {}
    };
}

const rl = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});
rl.on('line', (line) => {
    __lineDB.push(line);
});
rl.on('close', () => {
    process.stdout.write(solution(scanner) + '\n');
});
