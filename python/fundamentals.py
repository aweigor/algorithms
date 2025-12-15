# https://www.codewars.com/kata/568ff914fc7a40a18500005c
import ipaddress

from numpy import mean
from ipaddress import IPv4Address
def distances_from_average(test_list):
    avg = mean(test_list)
    return [round(avg - x, 2) for x in test_list]

def ips_between(start, end):
    return int(IPv4Address(end)) - int(IPv4Address(start))

def ips_between__oneliner(start, end):
    a = sum([int(e)*256**(3-i) for i, e in enumerate(start.split('.'))])
    b = sum([int(e)*256**(3-i) for i, e in enumerate(end.split('.'))])
    return abs(a-b)

def run_tests():
    result = ips_between('10.0.0.0', '10.0.1.0')
    print(result)

if __name__ == '__main__':
    run_tests()