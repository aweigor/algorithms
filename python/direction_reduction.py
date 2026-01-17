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