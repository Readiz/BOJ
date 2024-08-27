class PQ {
    constructor() {
        this.heap = [{time:0,cnt:0,r:-1,c:-1,dir:-1}]; // 실제보다 하나 더 많이 가지게 구성 (idx 편함)
    }
    swap(index1, index2) {
        [this.heap[index1], this.heap[index2]] = [this.heap[index2], this.heap[index1]];
    }
    push(x) {
        this.heap.push(x);
        for(let c = this.heap.length - 1; c > 1; c >>= 1) {
            let p = c >> 1;
            if (this.heap[p].time > this.heap[c].time) {
                this.swap(p, c);
            } else {
                break;
            }
        }
    }
    pop() {
        let ret = this.heap[1];
        this.swap(1, this.heap.length - 1);
        this.heap.pop();
        for (let c = 2; c < this.heap.length; c <<= 1) {
            if (c + 1 < this.heap.length && this.heap[c].time > this.heap[c+1].time) c = c + 1;
            let p = c >> 1;
            if (this.heap[p].time > this.heap[c].time) {
                this.swap(p, c);
            } else {
                break;
            }
        }
        return ret;
    }
}

function solution_14461(scanner) {
    const [N, T] = scanner.readLine().split(' ').map(Number);
    const map = [];
    const vis = Array.from({ length: N }, () =>
        Array.from({ length: N }, () =>
            Array(3).fill(0)
        )
    );
    for(let i = 0; i < N; ++i) {
        map.push(scanner.readLine().split(' ').map(Number));
    }
    const pq = new PQ();
    const dr = [1, 0, -1, 0];
    const dc = [0, 1, 0, -1];
    pq.push({time:0,cnt:0,r:0,c:0,dir:0});

    while(pq.heap.length > 1) {
        let cur = pq.pop();
        if (cur.r == N - 1 && cur.c == N - 1) {
            return cur.time;
        }
        if(vis[cur.r][cur.c][cur.cnt]) continue;
        vis[cur.r][cur.c][cur.cnt] = 1;
        for(let p=0;p<4;++p) {
            let nr = cur.r + dr[p];
            let nc = cur.c + dc[p];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (vis[nr][nc][(cur.cnt + 1) % 3] == 1) continue;
            let ntime = cur.time + T;
            if ((cur.cnt + 1) % 3 == 0) ntime += map[nr][nc];
            pq.push({time:ntime,cnt:cur.cnt+1,r:nr,c:nc,dir:p});
        }
    }
    return -1;
}

function solution(scanner) {
    let TC = 1;
    // TC = scanner.readInt();
    let result = [];
    while(TC--) result.push(solution_14461(scanner));
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
