import sys
from collections import deque

input = sys.stdin.read

def join_authors(authors, length: int) -> list:
    i = 0
    res = []

    while i < length:
        authorCompleteName = authors[i] + ', ' + authors[i + 1]
        res.append(authorCompleteName)
        i += 2

def process_author_name(papers: list):
    for paper in papers:
        authorsRaw = paper.split(": ")[0]
        authors = authorsRaw.split(", ")
        res = []
        length = len(authors)

        if length % 2 == 0:
            res = join_authors(authors, length)

        else:
            last = authors.pop()
            res = join_authors(authors)
            res.append(last)
        
    return res

def calculate_erdos_number(papers: list, autores_consultados):
    # Key -> Author name
    # Value -> Authors connected (list)
    graph = {}
    for paper in papers:
        autores = process_author_name(paper, graph)
    

def main():
    casos = int(input())
    for caso in range(casos):
        if caso > 0:
            print()
   
    papers = []
    autores = []
    
    P, N = map(int, input().split())
    for _ in range(P):
        papers.append(input())
    
    for _ in range(N):
        autores.append(input())
        
        
    print(f"Scenario {caso + 1}")
    res = calculate_erdos_number(papers, autores_consultados)
        
    
       
   

if __name__ == "__main__":
	main()