# https://www.codewars.com/kata/54d81488b981293527000c8f
def sum_pairs(ints, s):
    inv = [s - x for x in ints]
    checked = []
    result = None
    for i in reversed(range(len(ints))):
        if ints[i] in checked:
            continue
        for j in reversed(range(i)):
            if ints[i] == inv[j]:
                result = [ints[i], ints[j]]
        checked.append(ints[i])
    return result

def sum_pairs_nocheck(ints, s):
    inv = [s - x for x in ints]

    for i in range(1, len(ints)):
        for j in range(i):
            if inv[j] == ints[i]:
                return [ints[j], ints[i]]

    return None

def sum_pairs_optimized_check(ints, s):
    checked = []
    result = None
    for i in range(len(ints)):
        if s - ints[i] in checked:
            return [s - ints[i], ints[i]]
        if not ints[i] in checked:
            checked.append(ints[i])
    return result

# не тормозит
def sum_pairs_optimized(lst, s):
    cache = set()
    for i in lst:
        if s - i in cache:
            return [s - i, i]
        cache.add(i)

def assert_equals(actual, expected, error):
    if actual != expected:
        raise RuntimeError(error)

def run_test(ints, s, expected, msg):
    actual = sum_pairs_optimized_check(ints, s)
    print(actual)
    assert_equals(actual, expected, f'{msg}')


def sample_tests():
    l9 = [1] * 10000000
    l5 = [10, 5, 2, 3, 7, 5]
    run_test(l5, 10, [3, 7], "First Match From Left")

if __name__ == '__main__':
    sample_tests()