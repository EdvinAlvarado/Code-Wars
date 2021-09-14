#!/usr/bin/env python

# My solution
def ip(n):
    return '.'.join(str((n := n % 256**(4-i)) // 256**(3-i)) for i in range(4))


# My favorite solution
def int32_to_ip(int32):
    return "{}.{}.{}.{}".format(*int32.to_bytes(4, 'big'))
