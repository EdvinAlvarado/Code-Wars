from collections import defaultdict

def stock_list(listOfArt, listOfCat):
    if listOfCat == [] or listOfArt == []:
        return ""
    cat_val = {}
    cat_val = defaultdict(lambda: 0,cat_val) #initalize to zero
    for item in listOfArt:
        art, val = item.split(" ")
        cat_val[art[0]] += int(val)
    return " - ".join([f'({cat} : {cat_val[cat]})' for cat in listOfCat])
