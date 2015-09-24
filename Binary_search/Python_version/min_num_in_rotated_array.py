def Min(numbers, length):
    if numbers == None or length <= 0:
        print "Invalid parameters"
        return None

    index1 = 0
    index2 = length - 1

    indexMid = index1
    while numbers[index1] >= numbers[index2]:
        if index2 - index1 == 1:
            indexMid = index2
            break

        indexMid = (index1 + index2)/2

        if numbers[index1] == numbers[index2] and \
            numbers[indexMid] == numbers[index1]:
            return MinInOrder(numbers, index1, index2)

        if numbers[indexMid] >= numbers[index1] :
            index1 = indexMid
        elif numbers[indexMid] <= numbers[index2]:
            index2 = indexMid

    return numbers[indexMid]

def MinInOrder(numbers, index1, index2):
    result = numbers[index1]
    for i in range(index1 + 1, index2 + 1):
        if result > numbers[i]:
            result = numbers[i]

    return result

#---------
num = [3, 4, 5, 1, 2]
print Min(num, len(num))
