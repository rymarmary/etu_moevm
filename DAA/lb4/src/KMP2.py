def prefix(string):
    pref = [0] * len(string)
    for i in range(1, len(string)):
        k = pref[i - 1]
        while k > 0 and string[k] != string[i]:
            k = pref[k - 1]
        if string[k] == string[i]:
            k += 1
        pref[i] = k
    return pref

def KMP(string1, string2):
    length1 = len(string1)
    length2 = len(string2)
    answer = []
    if length1 != length2:
        answer.append(-1)
        return answer
    pref = prefix(string2)
    k = 0
    for i in range(2*length2):
        while k > 0 and string1[i % length2] != string2[k]:
            k = pref[k-1]
            if k == 0:
                break
        if string1[i % len(string2)] == string2[k]:
            k += 1
        if k == length1:
            answer.append(i - length1 + 1)
            break
    if not answer:
        answer.append(-1)
    return answer

if __name__ == '__main__':
    string1 = input()
    string2 = input()
    print(*KMP(string1, string2), sep = ',')