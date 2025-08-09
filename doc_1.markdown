# 📝 Parentheses Balance Checker — Explained Like a Human  

## 💡 What This Program Does  
Ever seen code with mismatched brackets or parentheses and wondered, *“Why isn’t this compiling?!”*  
This program is basically a **bracket bouncer** — it checks your expression and decides whether every opening bracket `(`, `{`, `[` has its proper closing partner `)`, `}`, `]` in the right order.  

It uses a **stack** to keep track of what’s open and what still needs closing.  

---

## 🧱 The Building Blocks  

### **1. The Stack Structure**  
We have a simple `Stack` built as a `struct` with:  
- `items[100]` → where we store our characters (the brackets).  
- `top` → tells us the index of the most recent (top) item in the stack. Starts at `-1` when empty.  

---

### **2. Functions That Make It Work**  

- **`initStack(Stack *s)`** → Resets the stack to empty (`top = -1`).  
- **`isEmpty(Stack *s)`** → Returns `1` if empty, otherwise `0`.  
- **`isFull(Stack *s)`** → Returns `1` if the stack is maxed out.  
- **`push(Stack *s, char item)`** → Adds a new bracket to the top.  
- **`pop(Stack *s)`** → Removes and returns the last bracket we added. If the stack’s empty, returns `'\0'`.  
- **`isBalanced(char *exp)`** → The brains of the operation. Reads through each character of the expression:  
  - If it’s an opening bracket, push it on the stack.  
  - If it’s a closing bracket, pop from the stack and check if it matches the right opening type.  
  - If something doesn’t match or the stack is empty when it shouldn’t be → **unbalanced**.  

---

## ⚙ How the `main()` Works  

We test this on a few expressions:  
```c
"a + (b - c) * (d"
"m + [a - b * (c + d * {m)]"
"a + (b - c)"
