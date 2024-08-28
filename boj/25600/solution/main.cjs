function solution_25600(scanner) {
    const N = scanner.readInt();
    let ret = -1;
    
    for(let i = 0; i < N; ++i) {
        const [a,d,j] = scanner.readLine().split(' ').map(Number);
        if (a == (d+j)) {
            if (ret < 2 * a * (d+j)) ret = 2 * a * (d+j);
        } else {
            if (ret < a * (d+j)) ret = a * (d+j);
        }
    }

    return ret;
}

function solution(scanner) {
    let TC = 1;
    // TC = scanner.readInt();
    let result = [];
    while(TC--) result.push(solution_25600(scanner));
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
