function solution_14710(scanner) {
    const [a, b] = scanner.readLine().split(' ').map(Number);
    let h=0;
    let db = new Set();
    db.add('h:0,m:0');
    for(let m=1;m<360*12;++m) {
        if (m%12==0) {
            ++h;
            db.add(`h:${h},m:${m%360}`);
        }
    }
    if (db.has(`h:${a},m:${b}`)) {
        return 'O';
    }
    return 'X';
}

function solution(scanner) {
    let TC = 1;
    // TC = scanner.readInt();
    let result = [];
    while(TC--) result.push(solution_14710(scanner));
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
