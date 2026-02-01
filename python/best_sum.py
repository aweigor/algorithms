import time

# https://www.codewars.com/kata/55e7280b40e1c4a06d0000aa
# The function returns the "best" sum ie the biggest possible sum of k distances less than or equal to the given limit t, if that sum exists, or otherwise None
def choose_best(t,k,ls):
    if k == 0: return 0
    best = -1
    for i, v in enumerate(ls):
        if v > t: continue
        b = choose_best(t - v, k - 1, ls[i+1:])
        if b < 0: continue
        b += v
        if b > best and b <= t:
            best = b
    return best

def choose_best_sum(t, k, ls):
    c = choose_best(t,k,ls)
    if c <= 0 : return None
    return c

def assert_equals(actual, expected, error):
    print(f'testing {actual}')
    if actual != expected:
        raise RuntimeError(error)

def run_test(expected):
    actual = choose_best_sum(163,3,[50, 55, 56, 57, 58])
    assert_equals(actual, expected, f'expected {expected}, got {actual}')


def sample_tests():
    run_test(163)

if __name__ == '__main__':
    sample_tests()