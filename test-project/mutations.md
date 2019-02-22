
# Relational Operator Replacement (ROR)
Replace a single operand with another operand.

The operands are: `<,<=,>,>=,==,!=,true,false`

The implementation should use what is in literature called RORG (Relational
Operator Replacement Global) because it results in fewer mutations and less
amplification of infeasible mutants.

### RORG

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

## Why?
Mutations such as `<` for a boolean type is nonsensical in C++ or in C when the type is `_Bool`.

This schema is only applicable when the type of the expressions on both sides of an operator are of floating point type.

| Original Expression | Mutant 1 | Mutant 2 | Mutant 3 |
| ------------------- | -------- | -------- | ---------- |
| `x < y`             | `x > y`  |          | `false`    |
| `x > y`             | `x < y`  |          | `false`    |
| `x <= y`            | `x > y`  |          | `true`     |
| `x >= y`            | `x < y`  |          | `true`     |
| `x == y`            | `x <= y` | `x >= y` | `false`    |
| `x != y`            | `x < y`  | `x > y`  | `true`     |

*Note*: that `==` and `!=` isn't changed compared to the original mutation schema because normally they shouldn't be used for a floating point value but if they are, and it is a valid use, the original schema should work.

## Why?
The goal is to reduce the number of *undesired* mutants.

Strict equal is not recommended to ever use for floating point numbers. Because of this the test suite is probably not designed to catch these type of mutations which lead to *undesired* mutants. They are *techincally* not equivalent but they aren't supposed to be cought because the SUT is never supposed to do these type of operations.

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

If the `x != y` is true then a change to a relational operator is equivalent to always `true`.

## Why?
The goal is to reduce the number of equivalent mutants.
Normally an enum can't be *outside* the boundaries of an enum thus the test suite can't possibly kill such a mutants that would require an enum outside the boundaries.

This schema is only applicable when type of the expressions either sides is a pointer type.

| Original Expression | Mutant 1 | Mutant 2 | Mutant 3 |
| ------------------- | -------- | -------- | -------- |
| `x < y`             | `x <= y` | `x != y` | `false`  |
| `x > y`             | `x >= y` | `x != y` | `false`  |
| `x <= y`            | `x < y`  | `x == y` | `true`   |
| `x >= y`            | `x > y`  | `x == y` | `true`   |
| `x == y`            | `x != y` | `false`  |
| `x != y`            | `x == y` | `true`   |

## Why?
The goal is to reduce the number of undesired mutants when the user of the plugin has knowledge about the internal design of the program.
Design knowledge: Do the program use such C++ constructs that guarantee memory address order and use this guarantees?

This schema can't fully replace parts of ROR because there are programs that make use of the memory address order that is guaranteed by the language. It is thus left to the user to choose the correct schema.

# Arithmetic Operator Replacement (AOR)
Replace a single arithmetic operator with another operand.

| Original | 1   | 2   | 3       | 4       | 5       | 6       |
|----------|-----|-----|---------|---------|---------|---------|
| `x + y`  | `x` | `y` | `x - y` | `x * y` | `x / y` | `x % y` |
| `x - y`  | `x` | `y` | `x + y` | `x * y` | `x / y` | `x % y` |
| `x * y`  | `x` | `y` | `x - y` | `x + y` | `x / y` | `x % y` |
| `x / y`  | `x` | `y` | `x - y` | `x * y` | `x + y` | `x % y` |
| `x % y`  | `x` | `y` | `x - y` | `x * y` | `x / y` | `x + y` |

# Logical Connector Replacement (LCR)
Replace a logical operand with the inverse.

| Original | 1        | 2        | 3        | 4   | 5   |
|----------|----------|----------|----------|-----|-----|
| `x && y` | `x || y` | `true`   | `false`  | `x` | `y` |
| `x || y` | `x && y` | `true`   | `false`  | `x` | `y` |

# Logical Connector Replacement Bit-wise (LCRB)
These two bitwise operators correlate well with the LCR operator. Coverage tools have a general problem with bitwise operators. This mutation operator can replace the manual coverage inspection activity when bitwise operators are used.

| Original Expression | Mutant 1 |
| ------------------- | -------- |
| `x | y`             | `x & y`  |
| `x & y`             | `x | y`  |

| Original | 1       | 2   | 3   |
|----------|---------|-----|-----|
| `x & y`  | `x | y` | `x` | `y` |
| `x | y`  | `x & y` | `x` | `y` |


# Unary Operator Insertion (UOI)
Insert a single unary operator in expressions where it is possible.
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
 
The cast operator is ignored because it is *probably* not possible to create
any useful mutant with it.
 * Cast: (type-name) cast-expression

Note: The address, indirection and complement operator need to be evaluated to
see how efficient those mutants are.
Are most mutants killed? Compilation errors?

# Absolute Value Insertion (ABS)
Replace a numerical expression with the absolute value.

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

## Undesired Mutant

Based on empirical observations integer literals are not mutated because they usually result in equivalent mutants.
Further studies on this subject is needed.

> The mutation abs(0) and abs(0.0) is undesired because it has no semantic effect.
> Note though that abs(-0.0) is a separate case.

# Conditional Operator Replacement (COR)
This mutation subsumes LCR and all negation mutations generated by UOI.

> Generally, valid mutations for a conditional expression such as a <op> b,
> where <op> denotes one of the logical connectors, include the following:
>  * a&&b : Apply the logical connector AND
>  * a||b : Apply the logical connector OR
>  * a==b : Apply the relational operator a==b
>  * a!=b : Apply the relational operator a!=b
>  * lhs : Return the value of the left hand side operand
>  * rhs : Return the value of the right hand side operand
>  * true : Always evaluate to the boolean value true
>  * false : Always evaluate to the boolean value false

| Original Expression | Mutant 1 | Mutant 2 | Mutant 3 | Mutant 4 |
| ------------------- | -------- | -------- | -------- | -------- |
| `a && b`            | `false`  | `a`      | `b`      | `a == b` |
| `a OR b`            | `true`   | `a`      | `b`      | `a != b` |

# Decision/Condition Coverage (DCC)

The intention is to be at least equivalent to a coverage tools report for decision/condition coverage.
This is the reason why a *bomb* is part of DCC.

## Why?
A test suite that achieve MC/DC should kill 100% of these mutants.

## Decision Coverage
The DC criteria requires that all branches in a program are executed.

## Condition Coverage
The CC criteria requires that all conditions clauses are executed with true/false.

## Bomb
A statement that halts the program.

The DCC bomb is only needed for case statements.
Note that the bomb do not provide any more information than a coverage report do because it doesn't force the test suite to check the output of the program. It is equivalent to coverage information.

# Decision/Condition Replacement (DCR)

## Why?
This is a twist of DCC. It replaces the bomb with statement deletion.
The intention is to require the test suite to check the output.

## Case Deletion
This is only needed for switch statements.
It *deactivates* the functionality in the case branch in a switch statement.

It is **more** equivalent to the DCC mutation for predicates (decision) that is set to *false* than using a bomb for the branch because deleting the functionality requires the test suite to *test* the side effect to be able to kill the mutant.
It isn't enough to *visit* the branch which is the case for a bomb.

Motivation why it is equivalent.

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

The intention of DCR is to test that the test suite verify logical expressions.
It is assumed that a function that returns bool is used in logical expressions in *some* way.
This use should be verified by the test suite.

# Statement Deletion (SDL)

Delete one statement at a time.

The plugin shall remove the specific function call.

**Note**: How it is removed depend on where it is in the AST.
A function call that is terminated with a `;` should remove the trailing `;`.
In contrast with the initialization list where it should remove the trailing `,`.

The plugin shall remove the content of the specified void function body.

## Rationale
This is useful to force a test case to demonstrate that a function has
observable and testable side effects. It is a *high probability* that when the
body is deleted and test cases do not kill the mutant that the function is
*unused* or *dead code*.

## To Prove
This type of mutation is *probably* more useful for C++ object oriented code
because it forces tests to kill methods that have a void return type.
