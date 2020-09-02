/**
 * The post increment operator (i++) is more resource consuming that pre-increment (++i).
 * This is because post increment operator creates a copy of the variable, then adds to it,
 * which is not the case for pre-increment. Hence, where possible, we use pre-increment.
 * Moreover, most compilers substitute post with pre increment operator when possible.
 */ 