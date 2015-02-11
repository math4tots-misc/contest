import sys, itertools, fractions

with open(sys.argv[1]) as f:
  for line in f.read().strip().splitlines():
    op_stack = []
    value_stack = []
    for token in line.split():

      if token in '+*/':
        op_stack.append(token)
      else:
        value_stack.append(fractions.Fraction(token))

      while len(value_stack) > 1:
        op = op_stack.pop()
        rhs = value_stack.pop()
        lhs = value_stack.pop()

        if op == '+':
          value_stack.append(lhs + rhs)

        elif op == '*':
          value_stack.append(lhs * rhs)

        else:
          value_stack.append(lhs / rhs)

    print(int(value_stack[0]))
