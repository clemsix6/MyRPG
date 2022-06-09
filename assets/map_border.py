from re import I, L


f = open('collisions.txt', 'r')
content = f.read()
f.close()

lines = content.split('\n')
for index in range(len(lines)):
    if len(lines[index]) < 1:
        continue
    l = list(lines[index])
    l[0] = '1'
    l[len(l) - 1] = '1'
    lines[index] = ''.join(l)
content = '\n'.join(lines)

f = open('collisions.txt', 'w')
f.write(content)
print(content)
f.close()