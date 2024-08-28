function solution_17122(scanner) {
    const chessBoardColors = {
        "A1": "black", "A2": "white", "A3": "black", "A4": "white", "A5": "black", "A6": "white", "A7": "black", "A8": "white",
        "B1": "white", "B2": "black", "B3": "white", "B4": "black", "B5": "white", "B6": "black", "B7": "white", "B8": "black",
        "C1": "black", "C2": "white", "C3": "black", "C4": "white", "C5": "black", "C6": "white", "C7": "black", "C8": "white",
        "D1": "white", "D2": "black", "D3": "white", "D4": "black", "D5": "white", "D6": "black", "D7": "white", "D8": "black",
        "E1": "black", "E2": "white", "E3": "black", "E4": "white", "E5": "black", "E6": "white", "E7": "black", "E8": "white",
        "F1": "white", "F2": "black", "F3": "white", "F4": "black", "F5": "white", "F6": "black", "F7": "white", "F8": "black",
        "G1": "black", "G2": "white", "G3": "black", "G4": "white", "G5": "black", "G6": "white", "G7": "black", "G8": "white",
        "H1": "white", "H2": "black", "H3": "white", "H4": "black", "H5": "white", "H6": "black", "H7": "white", "H8": "black"
    };
    const chessBoardColorsByNumber = {
        "1": "black",  "2": "white",  "3": "black",  "4": "white",  "5": "black",  "6": "white",  "7": "black",  "8": "white",
        "9": "white",  "10": "black", "11": "white", "12": "black", "13": "white", "14": "black", "15": "white", "16": "black",
        "17": "black", "18": "white", "19": "black", "20": "white", "21": "black", "22": "white", "23": "black", "24": "white",
        "25": "white", "26": "black", "27": "white", "28": "black", "29": "white", "30": "black", "31": "white", "32": "black",
        "33": "black", "34": "white", "35": "black", "36": "white", "37": "black", "38": "white", "39": "black", "40": "white",
        "41": "white", "42": "black", "43": "white", "44": "black", "45": "white", "46": "black", "47": "white", "48": "black",
        "49": "black", "50": "white", "51": "black", "52": "white", "53": "black", "54": "white", "55": "black", "56": "white",
        "57": "white", "58": "black", "59": "white", "60": "black", "61": "white", "62": "black", "63": "white", "64": "black"
    };

    const [a, b] = scanner.readLine().split(' ');
    if (chessBoardColors[a] == chessBoardColorsByNumber[b]) return "YES";
    else return "NO";
}

function solution(scanner) {
    let TC = 1;
    TC = scanner.readInt();
    let result = [];
    while(TC--) result.push(solution_17122(scanner));
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
