# https://www.codewars.com/kata/568ff914fc7a40a18500005c
from numpy import mean
def distances_from_average(test_list):
    avg = mean(test_list)
    return [round(avg - x, 2) for x in test_list]