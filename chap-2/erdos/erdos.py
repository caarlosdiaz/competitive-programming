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
        
        
        
        
   

if __name__ == "__main__":
	main()