def Dijkastra(matrix, start, end):
    size = len(matrix)
    dis = [matrix[start][i] for i in xrange(size)] # distance from
    prev= [start if dis[i] != INF else -1 for i in xrange(size)]

    visited = set()
    visited.add(start)
    for i in xrange(size):
        node   = -1  # closest node to visited area
        curDis = INF # the distance from closest node to visited area
        for j in xrange(size):
            if j not in visited and dis[j] < curDis:
                curDis = dis[j]
                node  = j

        visited.add(node)

        for j in xrange(size):
            if j not in visited and matrix[node][j] < INF:
                if dis[node] + matrix[node][j] < dis[j]:
                    dis[j] = dis[node] + matrix[node][j]
                    prev[j] = node

    path = [end]
    i = end
    while prev[i] != start:
        path = [ prev[i] ] + path
        i = prev[i]
    path = [ prev[i] ] + path

    return path

INF = float('inf')
graph = [
    [INF, 7, 9, INF, INF, 14],
    [7, INF, 10, 15, INF, INF],
    [9, 19, INF, 11, INF, 2],
    [INF, 15, 11, INF, 6, INF],
    [INF, INF, INF, 6, INF, 9],
    [14, INF, 2, INF, 9, INF]
]

print Dijkastra(graph, 0, 4)