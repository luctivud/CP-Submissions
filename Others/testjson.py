import json

d = {
    "OK" : 1, 
    "notOK" : [0, "1"]
}

obj = json.dumps(d, indent = 4)
with open("Zoutput.json", "w") as out:
    out.write(obj)