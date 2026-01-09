#https://www.codewars.com/kata/52597aa56021e91c93000cb0/

def move_zeros(lst):
    res = []
    zeros = 0
    for i in range(len(lst)):
        if lst[i] != 0:
            res.append(lst[i])
        else:
            zeros += 1
    for i in range(zeros):
        res.append(0)
    return res

def move_zeros_custom_sort(array):
    return sorted(array, key=lambda x: x==0 and type(x) is not bool)

def move_zeros_minimal(array):
    for i in array:
        if i == 0:
            array.remove(i) # Remove the element from the array
            array.append(i) # Append the element to the end
    return array

if __name__ == '__main__':
    print(move_zeros([1, 2, 0, 1, 0, 1, 0, 3, 0, 1])) # [1, 2, 1, 1, 3, 1, 0, 0, 0, 0]