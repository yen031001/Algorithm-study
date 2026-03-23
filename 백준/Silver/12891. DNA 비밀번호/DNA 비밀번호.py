import sys
input = sys.stdin.readline

s, p = map(int, input().split())
dna = input()
acgt = list(map(int, input().split()))
answer = 0
cnt_list = [0] * 4

for i in dna[:p]:
    if i == 'A':
        cnt_list[0] += 1
    elif i == 'C':
        cnt_list[1] += 1
    elif i == 'G':
        cnt_list[2] += 1
    elif i == 'T':
        cnt_list[3] += 1

if cnt_list[0] >= acgt[0] and cnt_list[1] >= acgt[1] and \
            cnt_list[2] >= acgt[2] and cnt_list[3] >= acgt[3]:
    answer += 1
        
for i in range(1, s-p+1):
    if dna[i-1] == 'A':
        cnt_list[0] -= 1
    elif dna[i-1] == 'C':
        cnt_list[1] -= 1
    elif dna[i-1] == 'G':
        cnt_list[2] -= 1
    elif dna[i-1] == 'T':
        cnt_list[3] -= 1

    if dna[i+p-1] == 'A':
        cnt_list[0] += 1
    elif dna[i+p-1] == 'C':
        cnt_list[1] += 1
    elif dna[i+p-1] == 'G':
        cnt_list[2] += 1
    elif dna[i+p-1] == 'T':
        cnt_list[3] += 1

    if cnt_list[0] >= acgt[0] and cnt_list[1] >= acgt[1] and \
            cnt_list[2] >= acgt[2] and cnt_list[3] >= acgt[3]:
        answer += 1

print(answer)
