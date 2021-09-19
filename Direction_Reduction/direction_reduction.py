from typing import List

def dirReduc(arr: List[str]) -> List[str]:
    red = []
    for d in arr:
        if red and (sorted((red[-1],d)) == sorted(("NORTH", "SOUTH")) or sorted((red[-1],d)) == sorted(("WEST", "EAST"))):
            red.pop()
        else:
            red.append(d)
    return red
