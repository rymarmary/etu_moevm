import graphviz
import time

time_pause = 0.1

def Graphics(graph, start, end):
    current, next_node = start, ''
    visited = [False] * 30
    visited[ord(current) - ord('a')] = True
    scheme = graphviz.Digraph()
    while current != end:
        for i in range(len(graph)):
            if current == graph[i][0] and not visited[ord(graph[i][1]) - ord('a')]:
                scheme.node(current, fontcolor='black')
                scheme.node(graph[i][1], fontcolor='black')
                scheme.edge(current, graph[i][1], label=str(graph[i][2]))
                scheme.render(f'{time.time()}.gv', view=True)
                time.sleep(time_pause)
        visited[ord(current) - ord('a')] = True
        current = chr(ord(current) + 1)


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
    Graphics(graph, start, end)