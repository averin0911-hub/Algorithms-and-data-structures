word_1 = input()
word_2 = input()

alp_1 = dict()
alp_2 = dict()

if len(word_1) == len(word_2):
    for i in range(len(word_1)):

        if word_1[i] not in alp_1:
            alp_1[word_1[i]] = 1
        else:
            alp_1[word_1[i]] += 1

        if word_2[i] not in alp_2:
            alp_2[word_2[i]] = 1
        else:
            alp_2[word_2[i]] += 1

    if alp_1 == alp_2:
        print("YES")
    else:
        print("NO")
        
else:
    print("NO")
