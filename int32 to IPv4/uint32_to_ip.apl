#!/usr/bin/apl --script

n ← ⍎⎕UCS (⎕FIO[41] 0)

ip←((1-⍨≢)⍴⊢){⊃,/'.',⍨¨⍕¨(4⍴256)⊤⍵}

ip n
)OFF
