import heapq

def heuristic(a, b):
    return abs(ord(a) - ord(b))

def aStar(graph, start, end):
    sum_path, path, priority_queue = {start: 0}, {start: None}, []
    heapq.heappush(priority_queue, [0, start])

    while len(priority_queue):
        current = heapq.heappop(priority_queue)[1]
        if current == end:
            break
        for i in range(len(graph)):
            if current == graph[i][0]:
                weight = sum_path[current] + graph[i][2]
                if graph[i][1] not in sum_path or weight < sum_path[graph[i][1]]:
                    sum_path[graph[i][1]] = weight
                    priority_number = weight + heuristic(end, graph[i][1])
                    heapq.heappush(priority_queue, [priority_number, graph[i][1]])
                    path[graph[i][1]] = current
    answer, previous = end, path[end]
    while previous is not None:
        answer = answer + previous
        previous = path[previous]
    return answer[::-1]

if __name__ == '__main__':
    start, end = input().split()
    graph = []
    while True:
        try:
            text = input()
        except EOFError:
            break
        if not text:
            break
        node1, node2, weight = text.split()
        graph.append([node1, node2, float(weight)])
    print(aStar(graph, start, end))
