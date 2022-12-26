def main():
    pattern = [ord(s) - 65 for s in input()]  # исходные строки, сразу переводим коды, с учетом ord('A') == 65
    text = [ord(s) - 65 for s in input()]
    print(*hash(pattern, text))

def hash(pattern, text):
    x, p = 59, 67  # простые
    answer = []

    x_pows = [1]  # степени x от 1 до m-1 по модулю p (чтобы не пересчитывать)
    for i in range(1, len(pattern)):
        x_pows.append(x_pows[-1] * x % p)

    # хеш паттерна в обратную сторону (тогда вывод идет в прямом порядке):
    # pattern[0] * x ^ (m-1)  + pattern[1] * x ^ (m-2) + ... pattern[m-1]
    pattern_hash = sum([pattern[i] * x_pows[len(pattern) - i - 1] for i in range(len(pattern))]) % p

    last_monoms = [text[i] * x_pows[-1] % p for i in range(len(text) - len(pattern) + 1)]  # последние мономы в хеше: text[i] * x ^ (m-1)

    cur_hash = (last_monoms[0] + sum(
        [text[i] * x_pows[len(pattern) - i - 1] for i in range(1, len(pattern))])) % p  # хеш первой подстроки, тоже в обратную сторону

    for i in range(len(text) - len(pattern)):  # цикл в прямом порядке

        if pattern_hash == cur_hash and pattern == text[i:(i + len(pattern))]:  # проверяем совпадение хеша и подстроки
            answer.append(i)

        cur_hash = ((cur_hash - last_monoms[i]) * x + text[
            i + len(pattern)]) % p  # пересчет хеша (в начале выталкиваем макс. степень, в конце прибавляем 0-вую

    if pattern_hash == cur_hash and pattern == text[(
            len(text) - len(pattern)):]:  # последняя подстрока, если добавить в цикл, то в пересчете хеша выйдем за границы массива
        answer.append(len(text) - len(pattern))   # в случае коллизии
    return answer

if __name__ == '__main__':
    main()