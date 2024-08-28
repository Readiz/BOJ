function solution_9437(scanner) {
    const [N, P] = scanner.readLine().split(' ').map(Number);
    let [a,b,c,d] = [1,2,N-1,N];
    if (N == 0) throw Error("force exit");

    let ret = [];
    while(b != c) {
        if (a == P) {
            ret = [b,c,d];
            break;
        } else if (b == P) {
            ret = [a,c,d];
            break;
        } else if (c == P) {
            ret = [a,b,d];
            break;
        } else if (d == P) {
            ret = [a,b,c];
            break;
        }
        a+=2;b+=2;c-=2;d-=2;
    }
    return ret.join(' ');
}

function solution(scanner) {
    let result = [];
    try {
        while(true) result.push(solution_9437(scanner));
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
