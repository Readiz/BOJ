function solution_13015(scanner) {
    const N = scanner.readInt();
    const ret = [];
    let line = '';
    for(let i=0;i<N;++i) line += '*';
    for(let i=0;i<2*(N-1)-1;++i) line += ' ';
    for(let i=0;i<N;++i) line += '*';
    ret.push(line);
    for(let k=1;k<N-1;++k) {
        let line = '';
        for(let i=0;i<k;++i) line += ' ';
        line += '*';
        for(let i=0;i<N-2;++i) line += ' ';
        line += '*';
        for(let i=0;i<2*(N-1-k)-1;++i) line += ' ';
        line += '*';
        for(let i=0;i<N-2;++i) line += ' ';
        line += '*';
        ret.push(line);
    }
    {
        let k=N-1;
        let line = '';
        for(let i=0;i<k;++i) line += ' ';
        line += '*';
        for(let i=0;i<N-2;++i) line += ' ';
        line += '*';
        for(let i=0;i<N-2;++i) line += ' ';
        line += '*';
        ret.push(line);
    }
    for(let k=N-2;k>=1;--k) {
        let line = '';
        for(let i=0;i<k;++i) line += ' ';
        line += '*';
        for(let i=0;i<N-2;++i) line += ' ';
        line += '*';
        for(let i=0;i<2*(N-1-k)-1;++i) line += ' ';
        line += '*';
        for(let i=0;i<N-2;++i) line += ' ';
        line += '*';
        ret.push(line);
    }
    line = '';
    for(let i=0;i<N;++i) line += '*';
    for(let i=0;i<2*(N-1)-1;++i) line += ' ';
    for(let i=0;i<N;++i) line += '*';
    ret.push(line);

    return ret.join('\n');
}

function solution(scanner) {
    let TC = 1;
    // TC = scanner.readInt();
    let result = '';
    while(TC--) result += solution_13015(scanner);
    return result;
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
} else {
    __lineDB = require('fs').readFileSync(process.argv[1].replace('.js', '_input.txt')).toString().split('\n');
    while (__lineIdx < __lineDB.length) {
        process.stdout.write('--------------------------------------------\n');
        process.stdout.write('New Start + Log\n');
        process.stdout.write('--------------------------------------------\n');
        const start = __lineIdx;
        const answer = solution(scanner);
        const end = __lineIdx;
        process.stdout.write('----------------------\n');
        process.stdout.write('Input\n')
        process.stdout.write('----------------------\n');
        process.stdout.write(__lineDB.slice(start, end).join('\n') + '\n');
        process.stdout.write('----------------------\n');
        process.stdout.write('Answer\n')
        process.stdout.write('----------------------\n');
        process.stdout.write(answer + '\n');
    }
}