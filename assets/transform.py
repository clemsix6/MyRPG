import json


def main():
    f = open('collisions.txt', 'w+')
    data = json.load(open("jsoncolision.json"))['layers'][0]['data']
    for i in range(len(data)):
        if data[i] != 748:
            data[i] = 1
        else:
            data[i] = 0
        f.write(str(data[i]))
        if i > 1 and i % 188 == 0:
            f.write('\n')
    f.close()


main()
