def func_read():
    matr_num = int(input())
    matrixes = []
    for i in range(matr_num):
        matr_size = int(input())
        matrix = []
        for k in range(matr_size):
            matr_string = list(map(int, input().split()))
            matrix.append(matr_string)
        matrixes.append(matrix)
    return matr_num, matrixes


def func_sum(matrix):
    sum = 0
    for i in range(len(matrix)):
        sum += matrix[i][i]
    return sum


def func_merge(list_matr, buf):
    if len(list_matr) == 1:
        return list_matr
    middle = len(list_matr) // 2
    left, right = list_matr[:middle], list_matr[middle:]
    func_merge(left, buf)
    func_merge(right, buf)
    index_left = index_right = index = 0
    result = [0] * (len(left) + len(right))
    while index_left < len(left) and index_right < len(right):
        if left[index_left][1] <= right[index_right][1]:
            result[index] = left[index_left]
            index_left += 1
        else:
            result[index] = right[index_right]
            index_right += 1
        index += 1
    while index_left < len(left):
        result[index] = left[index_left]
        index_left += 1
        index += 1
    while index_right < len(right):
        result[index] = right[index_right]
        index_right += 1
        index += 1
    for i in range(len(list_matr)):
        list_matr[i] = result[i]
    buf.append(list_matr)
    return list_matr


def main():
    num, matrixes = func_read()
    list_matr = list()
    buf = list()
    for i in range(num):
        list_matr.append((i, func_sum(matrixes[i])))
    res = func_merge(list_matr, buf)
    for n in range(len(buf)):
        tmp = ' '.join(map(lambda x: str(x[0]), sorted(buf[n], key=lambda pair:pair[1])))
        print(tmp)
    result = ' '.join(map(lambda x: str(x[0]), res))
    print(result)


if __name__ == '__main__':
    main()

