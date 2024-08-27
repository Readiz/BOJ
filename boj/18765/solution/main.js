let ret =
[
"+[]",//0
"+!![]",//1
"!![]+!![]",//2
"!![]+!![]+!![]",//3
"!![]+!![]+!![]+!![]",//4
"!![]+!![]+!![]+!![]+!![]",//5
"[!![]+!![]]*[!![]+!![]+!![]]",//6
"[+!![]+[+[]]]-!![]-!![]-!![]",//7
"[+!![]+[+[]]]-!![]-!![]",//8
"[+!![]+[+[]]]-!![]",//9
"+[+!![]+[+[]]]",//10
]
ret[11]="+[[+!+[]]+[+!+[]]]"
ret[100] ="+[+!![]+[+[]]+[+[]]]"
ret[1000]="+[+!![]+[+[]]+[+[]]+[+[]]]"

let ret_str =
[
]
ret_str[10]="+!![]+[+[]]"
ret_str[11]="+!![]+[+[]]+[+[]]+[+[]]"
ret_str[100]="+!![]+[+[]]+[+[]]"
ret_str[1000]="+!![]+[+[]]+[+[]]+[+[]]"

function makeStr() {
    for(let i=0;i<=1000;++i) {
        let c=`${ret[i]}+[]`
        if (ret_str[i]) {
            if (ret_str[i].length > c.length) {
                ret_str[i]=c
            }
            continue;
        }
        ret_str[i]=c
    }
    for(let i=12;i<100;++i) {
        let localAns='[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]][[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]'
        if (ret[i]) localAns = ret[i]
        let c=`+[${ret_str[Math.floor(i/10)]}+${ret_str[i%10]}]`
        try{
            if (c.length < localAns.length&&eval(c)==i) localAns=c
        }catch(e){}
        ret[i]=localAns
        ret_str[i]=`${ret_str[Math.floor(i/10)]}+${ret_str[i%10]}`
    }
    for(let i=101;i<1000;++i) {
        let localAns='[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]][[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]'
        if (ret[i]) localAns = ret[i]
        let c=`+[${ret_str[Math.floor(i/10)]}+${ret_str[i%10]}]`
        try{
            if (c.length < localAns.length&&eval(c)==i) localAns=c
        }catch(e){}
        if(localAns=ret[i]) continue;
        ret[i]=localAns
        ret_str[i]=`${ret_str[Math.floor(i/10)]}+${ret_str[i%10]}`
    }
    for(let i=101;i<1000;++i) {
        let localAns='[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]][[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]'
        if (ret[i]) localAns = ret[i]
        let c=`+[${ret_str[Math.floor(i/100)]}+${ret_str[i%100]}]`
        try{
            if (c.length < localAns.length&&eval(c)==i) {
                localAns=c
            }
        }catch(e){}
        if(localAns=ret[i]) continue;
        ret[i]=localAns
        ret_str[i]=`${ret_str[Math.floor(i/100)]}+${ret_str[i%100]}`
    }
}

function isPrime(v) {
    for(let i=2;i*i<=v;++i) {
        if (v%i==0) return false;
    }
    return true;
}

function gen() {
    for(let i=4;i<=1000;++i) {
        // 소수 case
        let localAns='[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]][[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]'
        if (ret[i]) localAns = ret[i]
    
        if (!isPrime(i)) {
            for(let j=Math.floor(Math.sqrt(i));j>=2;--j) {
                if (i%j!=0) continue;
                let a = j;
                let b = Math.floor(i/j);
                let c=`${ret[a]}*${ret[b]}`
                try{
                    if (c.length < localAns.length&&eval(c)===i) localAns=c
                }catch(e){}
                c=`${ret[a]}*[${ret[b]}]`
                try{
                    if (c.length < localAns.length&&eval(c)===i) localAns=c
                }catch(e){}
                c=`[${ret[a]}]*${ret[b]}`
                try{
                    if (c.length < localAns.length&&eval(c)===i) localAns=c
                }catch(e){}
                c=`[${ret[a]}]*[${ret[b]}]`
                try{
                    if (c.length < localAns.length&&eval(c)===i) localAns=c
                }catch(e){}
            }
            // if (eval(ret[i])!=i) {
                //     console.error(i, ret[i]);
                //     break
                // }
        }
        let c=`${ret[i-1]}+!![]`
        try{
            if (c.length < localAns.length&&eval(c)===i) localAns=c
        }catch(e){}
        if (ret[i+1]) {
            c=`${ret[i+1]}-!![]`
            try{
                if (c.length < localAns.length&&eval(c)===i) localAns=c
            }catch(e){}
        }
        for(let sub=2;sub<100;++sub) {
            let from = i+sub;
            if (!ret[from]) continue;
            c=`${ret[from]}-${ret[sub]}`
            try{
                if (c.length < localAns.length&&eval(c)===i) localAns=c
            }catch(e){}
        }
        for(let add=2;add<100;++add) {
            let from = i-add;
            if (!ret[from]) continue;
            c=`${ret[from]}+${ret[add]}`
            try{
                if (c.length < localAns.length&&eval(c)===i) localAns=c
            }catch(e){}
        }
    
        ret[i]=localAns
    }
}

function con() {
    for(let i=0;i<=99;++i) {
        let c0=`+[${ret[i]}+[+[]]]`
        try{
            let target=Number(i+'0')
            if (c0.length < ret[target].length&&eval(c0)===target) ret[target]=c0
        }catch(e){}
        let c1=`+[${ret[i]}+[+!+[]]]`
        try{
            let target=Number(i+'1')
            if (c1.length < ret[target].length&&eval(c1)===target) ret[target]=c1
        }catch(e){}
        let _1c=`+[+!![]+[]+${ret[i]}]`
        try{
            let target=Number('1'+i)
            if (_1c.length < ret[target].length&&eval(_1c)===target) ret[target]=_1c
        }catch(e){}
        let _2c=`+[!![]+!![]+[]+${ret[i]}]`
        try{
            let target=Number('2'+i)
            if (_2c.length < ret[target].length&&eval(_2c)===target) ret[target]=_2c
        }catch(e){}
        let _3c=`+[!![]+!![]+!![]+[]+${ret[i]}]`
        try{
            let target=Number('3'+i)
            if (_3c.length < ret[target].length&&eval(_3c)===target) ret[target]=_3c
        }catch(e){}
    }
}

for(let i=0;i<100;++i) {
    gen();makeStr();
    for(let i=0;i<=1000;++i) {
        ret[i] = ret[i].replace('-+','-')
        ret[i] = ret[i].replace('*+','*')
        //ret[i] = ret[i].replace('[+','[') err
        if (i >= 2 && ret[i].startsWith('+[')) {
            try{
                let tmp = ret[i].substring(1);
                if (eval(tmp)===i) ret[i]=tmp
            }catch(e){}
        }
    }
    con();
}

for(let i=0;i<=1000;++i) {
    if(eval(ret[i])===i) continue;
    console.error('validation err!', i, ret[i], ret[i].length)
}

// let cnt=0;
// let long=0;
// for(let i=0;i<=1000;++i) {
//     if(ret[i].length > 75) {
//         console.error(i, ret[i], ret[i].length)
//         if(ret[i].length >long)long=ret[i].length;
//         ++cnt;
//     } else {
//         console.log(i, ret[i], ret[i].length)
//     }
// }
// console.error('not match cnt', cnt);
// console.error('longest', long);
// console.log(ret.map(_=>eval(_)))
// console.log(ret)

for(let i=0;i<=1000;++i)console.log(ret[i])