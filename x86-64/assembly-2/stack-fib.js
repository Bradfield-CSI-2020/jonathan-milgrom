
/**
 * Explicit Stack Fibannoci.
 * 
 * Recursive fib (f(n) = fn(n-1) + f(n-2)) will build up addition operations
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
 *  if children (n - 1 > 1), enqueue stack
 *  pop, then add.
 *  
 * @param {*} n 
 */
const stackFib = (n) => {
    if (n <= 1) {
        return n;
    }

    let total = 0;
    const stack = [];
    stack.push(n);

    while (stack.length) {
        const next = stack.pop();
        if (next <= 1) {
            total+=next;
        } else {
            stack.push(next-1);
            stack.push(next-2);
        }
    }

    return total;
};