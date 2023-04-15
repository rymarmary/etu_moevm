def greedy(graph, start, end):
    cur, res = start, [start]
    visited = [False] * 30
    visited[ord(cur) - ord('a')] = True
    while cur != end:
        min = float("inf")
        flag = False
        next_node = ''
        for i in range(len(graph)):
            if cur == graph[i][0]:
                if not visited[ord(graph[i][1]) - ord('a')] and graph[i][2] < min:
                    min = graph[i][2]
                    next_node = graph[i][1]
                    flag = True
        visited[ord(cur) - ord('a')] = True
        if not flag:
            if res:
                res.pop(-1)
                cur = res[-1]
            continue
        cur = next_node
        res.append(cur)
    return ''.join(res)

if __name__ == '__main__':
    start, end = map(str, input().split())
    list_nodes = []
    while True:
        try:
            data = input()
        except EOFError:
            break
        if not data:
            break
        node1, node2, weight = data.split()
        list_nodes.append([node1, node2, float(weight)])
    print(greedy(list_nodes, start, end))
