import string

def is_pangram(s):
    return set(s.lower()) >= set(string.ascii_lowercase) # same as issuperset https://docs.python.org/3/library/stdtypes.html#set

def is_pangram(s):
    return set(string.ascii_lowercase).issubset(s.lower())

def is_pangram(st):
    alpha = 'abcdefghijklmnopqrstuvwxyz'
    chs = {}
    for ch in st:
        chs[ch.lower()] = 1
    return all(ch in chs for ch in alpha)

if __name__ == '__main__':
    assert rot13('test') == 'grfg'
    assert rot13('Test') == 'Grfg'
    assert rot13('aA bB zZ 1234 *!?%') == 'nN oO mM 1234 *!?%'