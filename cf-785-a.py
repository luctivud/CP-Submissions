d = {}
d["Tetrahedron"] = 4
d["Cube"] = 6
d["Octahedron"] = 8
d["Dodecahedron"] = 12
d["Icosahedron"] = 20
ans = 0
for i in range(int(input())):
    ans += d[input()]
print(ans)