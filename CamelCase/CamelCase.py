import re

def to_camel_case(text):
    regex_list = re.findall(r"[A-Za-z]+", text)
    return regex_list[0] + "".join(r[0].upper() + r[1:] for r in regex_list[1:])

print(to_camel_case("the_stealth_warrior")
