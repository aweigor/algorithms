from collections import Counter

# https://www.codewars.com/kata/550f22f4d758534c1100025a
#
# { "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" } -> { "WEST" }
#
# reduc(aab) = abs(count(a) + count(b)) = a
# reduc(cda) = reduc(cd) + reduc(a) = a
# reduc(aabcda) = reduc(L) + reduc(R) = aa: L = aab, R = cda
#
# f():
# out: reduc(aabcda)
# while out != reduc(out):
#   out = reduc(out)
# return out

directionsMap = { 'N': 0, 'S': 1, 'E': 2, 'W': 3}

def reduc(direc):
    opposites = {"N": "S", "S": "N", "E": "W", "W": "E"}
    stack = []
    for d in direc:
        if stack and stack[-1] == opposites[d]:
            stack.pop()
        else:
            stack.append(d)
    return stack

def main():
    res = reduc(["N", "S", "S", "E", "W", "N", "W"])
    print(res)


if __name__ == '__main__':
    main()