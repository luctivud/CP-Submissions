import myModuleA4 as ud
print("Enter the numbers")
a, b = map(int, input().split())
print("Addition is", ud.add(a,b))
print("Subtraction is", ud.subt(a,b))
print("Multiplication is", ud.mul(a,b))
print("Division is", ud.div(a,b))
print("Modulus is", ud.mod(a,b))
