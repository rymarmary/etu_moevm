def treeHeight(nodeList, n):
    dictionary = dict()
    if nodeList == [] or n <= 0:
        raise ValueError("Wrong input")
    for i in range(n):
        height = 1
        node = nodeList[i]
        while node != -1:
            if node not in dictionary:
                node = nodeList[node]
                height += 1
            else:
                height += dictionary[node]
                break
        dictionary[i] = height
    return max(dictionary.values())

if __name__ == '__main__':
    num = int(input())
    nodeList = list(map(int, input().split()))
    print(treeHeight(nodeList, num))