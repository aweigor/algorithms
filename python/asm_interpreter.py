# https://www.codewars.com/kata/58e24788e24ddee28e000053
def simple_assembler(program):
    state = {}
    pointer = 0
    while pointer < len(program):
        instruction = program[pointer]
        components = instruction.split()
        match components[0]:
            case 'mov':
                if not len(components) == 3:
                    raise TypeError()
                if components[2].lstrip("-").isdigit():
                    state[components[1]] = int(components[2])
                elif components[2] in state:
                    state[components[1]] = state[components[2]]
            case 'inc':
                state[components[1]] += 1
            case 'dec':
                state[components[1]] -= 1
            case 'jnz':
                if not len(components) == 3:
                    raise TypeError()
                is_true = False
                if components[1].lstrip("-").isdigit():
                    is_true = int(components[2]) == 0
                elif components[1] in state:
                    is_true = state[components[1]] == 0
                if not is_true:
                    pointer += int(components[2])
                    continue
        pointer += 1
    return state

def assert_equals(actual, expected, error):
    print(f'testing {actual}')
    if actual != expected:
        raise RuntimeError(error)

def run_test(code, expected):
    actual = simple_assembler(code.splitlines())
    assert_equals(actual, expected, f'expected {expected}, got {actual}')


def sample_tests():
    program1 = '''\
mov a 5
dec a
jnz a -1
inc a'''
    program2 = '''\
mov c 12
mov b 0
mov a 200
dec a
inc b
jnz a -2
dec c
mov a b
jnz c -5
jnz 0 1
mov c a'''
    run_test(program1, {'a': 1})
    run_test(program2, {'a': 409600, 'c': 409600, 'b': 409600})

if __name__ == '__main__':
    sample_tests()