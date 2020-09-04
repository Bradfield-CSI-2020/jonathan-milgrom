const stack = [];

/**
 * Explicit Stack Fibannoci.
 * 
 * Recursive fib (f(n) = fn(n-1) + f(n-2)) build up addition operations
 * on the call stack e.g:
 * 
 *  f(3)
 *     |__f(2)
 *     |   |__f(1)
 *     |   |__f(0)
 *     |__f(1)
 * 
 * We want to model this behavior explicitly with a stack
 * 
 * Steps:
 *  
 *  pop x0, x1 from stack
 *  if x > 1, push x-1, x-2 unto stack
 *  
 * @param {*} n 
 */
const stackFib = (n) => {
    if (n <= 1) {
        return n;
    }

    stack.push(n - 1);
    stack.push(n - 2);

    while (stack.length) {
        const [x1, x2] = [stack.pop(), stack.pop()];
        if (x1 <= 1) {
            stack.push();
        }
    }
};