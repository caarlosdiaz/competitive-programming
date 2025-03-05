def calculateNumber(n: int):
    return n*(n-1)*(n-2)*(n-3)//24 + n*(n-1)//2 + 1

def main():
    cases = int(input())
    for _ in range(cases):
        n = int(input())
        if n == 0:
            print(1)
            continue
        print(calculateNumber(n))

if __name__ == "__main__":
    main()