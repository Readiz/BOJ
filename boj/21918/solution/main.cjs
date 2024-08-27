function solution_21918(scanner) {
    const [N, M] = scanner.readLine().split(' ').map(Number);
    const arr = scanner.readLine().split(' ').map(Number);
    
    for(let i = 0; i < M; ++i) {
        const [a, b, c] = scanner.readLine().split(' ').map(Number);
        if (a == 1) {
            arr[b-1]=c;
        } else if (a == 2) {
            for(let j = b-1; j <= c-1; ++j) {
                arr[j] = 1 - arr[j];
            }
        } else if (a == 3) {
            for(let j = b-1; j <= c-1; ++j) {
                arr[j] = 0;
            }
        } else if (a == 4) {
            for(let j = b-1; j <= c-1; ++j) {
                arr[j] = 1;
            }
        }
    }

    return arr.join(' ');
}

function solution(scanner) {
    let TC = 1;
    // TC = scanner.readInt();
    let result = '';
    while(TC--) result += solution_21918(scanner);
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