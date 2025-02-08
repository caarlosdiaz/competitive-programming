from collections import deque, defaultdict

# Key -> Author name
# Value -> Authors connected (list)
authorsGraph = defaultdict(set)
authorsWeight = {}

def join_authors(authors, length: int) -> list:
    i = 0
    res = []

    while i < length:
        authorCompleteName = authors[i] + ', ' + authors[i + 1]
        res.append(authorCompleteName)
        i += 2
    
    return res

def process_author_name(paper: str):
    authorsRaw = paper.split(": ")[0]
    authors = authorsRaw.split(", ")
    res = []
    length = len(authors)
    

    if length % 2 == 0:
        res = join_authors(authors, length)

    else:
        length -= 1
        last = authors.pop()
        res = join_authors(authors, length)
        res.append(last)
        
    return res

def calculate_erdos_number():
    initial_node = "Erdos, P."
    if initial_node not in authorsGraph:
        print("Erdos not in graph")
        return

    queue = deque()
    queue.append(initial_node)
    authorsWeight[initial_node] = 0

    while queue:
        node = queue.popleft()

        navigableNodes = authorsGraph[node]
        
        for nd in navigableNodes:
            if nd in authorsWeight:
                continue
            queue.append(nd)
            authorsWeight[nd] = authorsWeight[node] + 1

def get_erdos_number(author):
    if author not in authorsGraph:
        print(author + " infinity")
        return
    
    if author in authorsWeight:
        print(author + " " + str(authorsWeight[author]))
        return
    
    print(author + " infinity")

def main():
    casos = int(input())
    for caso in range(casos):
        authorsGraph.clear()
        authorsWeight.clear()
   
        papers = []
        authorsToCalc = []
        
        P, N = map(int, input().split())
        for _ in range(P):
            papers.append(input())
        
        for _ in range(N):
            authorsToCalc.append(input())

        for paper in papers:
            authors = process_author_name(paper)
            for a in authors:
                authorsGraph[a].update(set(authors) - {a})

        calculate_erdos_number()

        print("Scenario " + str(caso + 1))

        for author in authorsToCalc:
            get_erdos_number(author)

if __name__ == "__main__":
	main()