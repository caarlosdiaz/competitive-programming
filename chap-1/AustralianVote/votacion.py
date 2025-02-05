def procesar_votos():
	n = int(input())

	candidatos = []
	for _ in range(n):
		candidatos.append(input())

	votos = []
	while True:
		try:
			linea = input().strip()
			if not linea:
				break
			voto = list(map(int, linea.split()))
			votos.append(voto)
		except EOFError:
			break

	eliminados = set()
	
	while True:
		conteo = [0] * n
		for voto in votos:
			for candidato in voto:
				if candidato - 1 not in eliminados:
					conteo[candidato - 1] += 1
					break
		
		total_votos = sum(conteo)

		for i, votos_candidato in enumerate(conteo):
			if i not in eliminados and votos_candidato > total_votos / 2:
				return [candidatos[i]]
		
		votos_restantes = set()
		for i, num_votos in enumerate(conteo):
			if i not in eliminados:
				votos_restantes.add(num_votos)

		if len(votos_restantes) == 1:
			return [candidatos[i] for i in range(n) if i not in eliminados]

		min_votos = float('inf')
		for i, votos_candidato in enumerate(conteo):
			if i not in eliminados and votos_candidato < min_votos:
				min_votos = votos_candidato

		for i, votos_candidato in enumerate(conteo):
			if i not in eliminados and votos_candidato == min_votos:
				eliminados.add(i)
	

def main():
	casos = int(input())
	input() #linea en blanco

	for caso in range(casos):
		if caso > 0:
			print()

		ganadores = procesar_votos()
		for ganador in ganadores:
			print(ganador)

if __name__ == "__main__":
	main()