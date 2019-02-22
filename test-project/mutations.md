
# Relational Operator Replacement (ROR)

| Original Expression | Mutant 1 | Mutant 2 | Mutant 3 |
|---------------------|----------|----------|----------|
| `x < y`             | `x <= y` | `x != y` | `false`  |
| `x > y`             | `x >= y` | `x != y` | `false`  |
| `x <= y`            | `x < y`  | `x == y` | `true`   |
| `x >= y`            | `x > y`  | `x == y` | `true`   |
| `x == y`            | `x <= y` | `x >= y` | `false`  |
| `x != y`            | `x < y`  | `x > y`  | `true`   |

This schema is only applicable when the type of the expressions on both sides of an operator are of boolean type.

| Original Expression | Mutant 1 | Mutant 2 |
| ------------------- | -------- | -------- |
| `x == y`            | `x != y` |  `false` |
| `x != y`            | `x == y` |  `true`  |

This schema is only applicable when the type of the expressions on both sides of an operator are of floating point type.

| Original Expression | Mutant 1 | Mutant 2 | Mutant 3 |
| ------------------- | -------- | -------- | ---------- |
| `x < y`             | `x > y`  |          | `false`    |
| `x > y`             | `x < y`  |          | `false`    |
| `x <= y`            | `x > y`  |          | `true`     |
| `x >= y`            | `x < y`  |          | `true`     |
| `x == y`            | `x <= y` | `x >= y` | `false`    |
| `x != y`            | `x < y`  | `x > y`  | `true`     |

This schema is only applicable when type of the expressions on both sides of an operator are enums and the same enum type.

| Original Expression | Mutant 1 | Mutant 2 | Mutant 3 |
| ------------------- | -------- | -------- | -------- |
| `x < y`             | `x <= y` | `x != y` | `false`  |
| `x > y`             | `x >= y` | `x != y` | `false`  |
| `x <= y`            | `x < y`  | `x == y` | `true`   |
| `x >= y`            | `x > y`  | `x == y` | `true`   |
| `x == y`            | `false`  |          |          |
| `x != y`            | `true`   |          |          |


Specific additional schema for equal:

| Original Expression | Mutant 1 | Condition                    | Always |
| ------------------- | -------- | ---------------------------- | ------ |
| `x == y`            | `x <= y` | if x is the min enum literal | `true` |
| `x == y`            | `x >= y` | if x is the max enum literal | `true` |
| `x == y`            | `x >= y` | if y is the min enum literal | `true` |
| `x == y`            | `x <= y` | if y is the max enum literal | `true` |

Specific additional schema for not equal:

| Original Expression | Mutant 1 | Condition                    | Always |
| ------------------- | -------- | ---------------------------- | ------ |
| `x != y`            | `x < y`  | if x is the min enum literal | `true` |
| `x != y`            | `x > y`  | if x is the max enum literal | `true` |
| `x != y`            | `x > y`  | if y is the min enum literal | `true` |
| `x != y`            | `x < y`  | if y is the max enum literal | `true` |

This schema is only applicable when type\

of the expressions either sides is a pointer\

type.

| Original Expression | Mutant 1 | Mutant 2 | Mutant 3 |
| ------------------- | -------- | -------- | -------- |
| `x < y`             | `x <= y` | `x != y` | `false`  |
| `x > y`             | `x >= y` | `x != y` | `false`  |
| `x <= y`            | `x < y`  | `x == y` | `true`   |
| `x >= y`            | `x > y`  | `x == y` | `true`   |
| `x == y`            | `x != y` | `false`  |
| `x != y`            | `x == y` | `true`   |


# Arithmetic Operator Replacement (AOR)

| Original | 1   | 2   | 3       | 4       | 5       | 6       |
|----------|-----|-----|---------|---------|---------|---------|
| `x + y`  | `x` | `y` | `x - y` | `x * y` | `x / y` | `x % y` |
| `x - y`  | `x` | `y` | `x + y` | `x * y` | `x / y` | `x % y` |
| `x * y`  | `x` | `y` | `x - y` | `x + y` | `x / y` | `x % y` |
| `x / y`  | `x` | `y` | `x - y` | `x * y` | `x + y` | `x % y` |
| `x % y`  | `x` | `y` | `x - y` | `x * y` | `x / y` | `x + y` |


# Logical Connector Replacement (LCR)

| Original | 1        | 2        | 3        | 4   | 5   |
|----------|----------|----------|----------|-----|-----|
| `x && y` | `x || y` | `true`   | `false`  | `x` | `y` |
| `x || y` | `x && y` | `true`   | `false`  | `x` | `y` |


# Unary Operator Insertion (UOI)
The operands are:
 * Increment: ++x, x++
 * Decrement: --x, x--
 * Address: &x
 * Indirection: *x
 * Positive: +x
 * Negative: -x
 * Ones' complement: ~x
 * Logical negation: !x
 * Sizeof: sizeof x, sizeof(type-name)
 
 
# Absolute Value Insertion (ABS)
Example:
```cpp
// original
a = b + c
// the absolute value
a = abs(b + c)
// the negative absolute value
a = -abs(b + c)
// a bomb that go of if the expression is evaluated to zero
a = fail_on_zero(b + c)
```


# Conditional Operator Replacement (COR)

| Original Expression | Mutant 1 | Mutant 2 | Mutant 3 | Mutant 4 |
| ------------------- | -------- | -------- | -------- | -------- |
| `a && b`            | `false`  | `a`      | `b`      | `a == b` |
| `a OR b`            | `true`   | `a`      | `b`      | `a != b` |


# Decision/Condition Coverage (DCC)
The intention is to be at least equivalent to a coverage tools report for decision/condition coverage.
This is the reason why a *bomb* is part of DCC.


# Decision/Condition Replacement (DCR)
## Case Deletion
Consider the following switch statement:
```cpp
switch (x) {
case A: y = 1; break;
case B: y = 2; break;
default: y = 3; break;
}
```

It can be rewritten as:
```cpp
if (x == A) { y = 1; }
else if (x == B) { y = 2; }
else { y = 3; }
```

A decision mutation of the first branch is equivalent to replacement of `x == A` with `true`/`false`.
```cpp
if (false) { y = 1; }
else if (x == B) { y = 2; }
else { y = 3; }
```

Note that when it is set to `false` it is equivalent to *never* being taken.
It is thus equivalent to the rewrite:
```cpp
if (x == B) { y = 2; }
else { y = 3; }
```

The branch is deleted.
Thus `false` is equivalent to statement deletion of the branch content.


# Statement Deletion (SDL)
Delete one statement at a time.
