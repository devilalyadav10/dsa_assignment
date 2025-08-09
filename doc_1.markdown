# Parentheses Balance Checker — Documentation

## (a) Data structures — how they are defined

### `#define MAXSIZE 100`
- Constant that sets the fixed maximum capacity of the stack array.
- All stack operations assume indices valid in `[0, MAXSIZE-1]`.

### `typedef struct Stack {`
- `char items[MAXSIZE];`  
  - Fixed-size array used to store bracket characters: `'('`, `')'`, `'['`, `']'`, `'{'`, `'}'`.
  - Characters are stored in insertion order; the top of the stack is the most recently pushed element.
- `int top;`  
  - Index of the current top element in `items`.
  - **Invariant:** when stack is empty, `top == -1`. When stack has one element, `top == 0`.
  - **Full condition:** `top == MAXSIZE - 1`.

**Summary of state invariants**
- Empty stack: `top == -1`
- Non-empty: `0 <= top < MAXSIZE`
- Full stack: `top == MAXSIZE - 1`

---

## (b) Functions implemented — prototypes, purpose, behavior, edge cases

> All prototypes use `Stack *s` to modify/check the same stack instance.

### `void initStack(Stack *s);`
- **Purpose:** Initialize a `Stack` instance to the empty state.
- **Behavior:** Sets `s->top = -1`.
- **Side effects:** Alters `s->top`. `s->items` contents are left as-is; only `top` matters.

### `int isEmpty(const Stack *s);`
- **Purpose:** Query whether the stack currently contains zero items.
- **Returns:** `1` if `s->top == -1`, otherwise `0`.
- **Side effects:** None.

### `int isFull(const Stack *s);`
- **Purpose:** Query whether the stack is at capacity.
- **Returns:** `1` if `s->top == MAXSIZE - 1`, otherwise `0`.
- **Side effects:** None.

### `void push(Stack *s, char item);`
- **Purpose:** Push a character onto the top of the stack.
- **Behavior:**  
  - If `isFull(s)` is `0`, increments `s->top` then stores `item` at `s->items[s->top]`.  
  - If the stack is full, **push is a no-op** (implementation can also log or set an error; in the canonical simple implementation it silently ignores the push to avoid overflow).
- **Return value:** none (void).
- **Edge cases:** If the caller keeps pushing after full, new items are ignored.

### `char pop(Stack *s);`
- **Purpose:** Remove and return the top character from the stack.
- **Behavior:**  
  - If `isEmpty(s)` is `0` (not empty), returns `s->items[s->top]` and then decrements `s->top`.  
  - If the stack is empty, returns the sentinel `'\0'` to indicate underflow / nothing to pop.
- **Return value:** popped `char` or `'\0'` for empty stack.
- **Side effects:** Decrements `s->top` when an item is returned.

### `int isMatchingPair(char open, char close);`
- **Purpose:** Helper: given an opening bracket and a closing bracket, determine if they form a correct pair.
- **Behavior:** returns `1` if `(open == '(' && close == ')')`, or `[`/`]`, or `{`/`}`, otherwise `0`.
- **Side effects:** None.

### `int isBalanced(const char *exp);`
- **Purpose:** Determine whether the bracket characters in `exp` form a balanced sequence.
- **Algorithm / Step-by-step behavior:**
  1. Create and initialize a `Stack s` (`initStack(&s)`).
  2. Iterate characters `c` from `exp` (until `'\0'`):
     - If `c` is an **opening bracket** (`'('`, `'['`, `'{'`): call `push(&s, c)`.
     - If `c` is a **closing bracket** (`')'`, `']'`, `'}'`):
       - Call `pop(&s)` to get `topChar`.
       - If `topChar == '\0'` (stack underflow) → **unbalanced** (return `0`).
       - Else if `!isMatchingPair(topChar, c)` → **unbalanced** (return `0`).
     - If `c` is any other character → ignore and continue.
  3. After iteration, if `isEmpty(&s)` is `1` → **balanced** (return `1`). Otherwise → **unbalanced** (return `0`).
- **Return value:** `1` if balanced, `0` if not.
- **Edge cases & notes:**
  - If expression contains more closing brackets than openings, an underflow will occur and `isBalanced` will return `0`.
  - If expression contains more openings than closings, remaining items in the stack make `isBalanced` return `0`.
  - Non-bracket characters do not affect the result.
  - Stack overflow (pushing > `MAXSIZE`) is possible for extremely long expressions; in that case pushes become no-ops and correctness may be compromised. With `MAXSIZE = 100` typical code assumes expressions are shorter than 100 bracket characters.

---

## (c) `main()` overview — how it is organized

**High-level structure**
1. Prepare a list/array of test input expressions (C-style `char *` strings).
2. For each expression:
   - Call `isBalanced(expression)`.
   - Print the input expression (optionally) and print the result as either `Balanced` or `Not Balanced`.
3. Exit program.

**Canonical `main()` pseudo-C layout**
```c
int main(void) {
    const char *tests[] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)",
        NULL
    };

    for (int i = 0; tests[i] != NULL; ++i) {
        const char *expr = tests[i];
        int ok = isBalanced(expr);   // returns 1 or 0
        printf("Expression: %s\n", expr);
        if (ok) {
            printf("Result: Balanced\n\n");
        } else {
            printf("Result: Not Balanced\n\n");
        }
    }
    return 0;
}
