function solution_8911(scanner) {
    const CMD = scanner.readLine();
    let x = 0, y = 0;
    const dx=[1,0,-1,0];
    const dy=[0,1,0,-1];
    let p=0;
    
    let x_max = 0;
    let x_min = 0;
    let y_max = 0;
    let y_min = 0;
    

    for(let i = 0; i < CMD.length; ++i) {
        switch (CMD[i]) {
            case 'F':
            x += dx[p];
            y += dy[p];
            break;
            case 'B':
            x -= dx[p];
            y -= dy[p];
            break;
            case 'L':
            p=(p+1)%4;
            break;
            case 'R':
            p=(p+3)%4;
            break;
        }
        if (x_max < x) x_max = x;
        if (x_min > x) x_min = x;
        if (y_max < y) y_max = y;
        if (y_min > y) y_min = y;
    }

    return (x_max-x_min)*(y_max-y_min)+'\n'
}

function solution(scanner) {
    let TC = 1;
    TC = scanner.readInt();
    let result = '';
    while(TC--) result += solution_8911(scanner);
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