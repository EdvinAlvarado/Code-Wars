def wave(s):
    return [s[:i] + c.upper() + s[i+1:] for i,c in enumerate(s) if c != ' ']

