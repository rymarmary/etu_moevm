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


def KMP(pattern, text):
    answer = []
    pref = prefix(pattern + '#' + text)
    for i in range(len(text)):
        if pref[i + len(pattern) + 1] == len(pattern):
            answer.append(str(i - len(pattern) + 1))
    return answer if answer != [] else ["-1"]

if __name__ == '__main__':
    pattern = input()
    text = input()
    print(",".join(KMP(pattern, text)))