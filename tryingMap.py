def fun(variable): 
    letters = ['a', 'e', 'i', 'o', 'u'] 
    if (variable in letters): 
        return True
    else: 
        return False
checkAlpha = ['u','d','i','t']
filteredLetters = list(filter(fun, checkAlpha))
print(filteredLetters)