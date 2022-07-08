let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Documents/Code-Wars/Array.diff
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +11 ~/Documents/Code-Wars/Array.diff/arrayDiff.c
badd +3 ~/Documents/Code-Wars/Array.diff/arrayDiff.hs
badd +2 ~/Documents/Code-Wars/Array.diff/arrayDiff.py
badd +0 ~/Documents/Code-Wars/Array.diff/arrayDiff.rs
badd +9 ~/Documents/Code-Wars/Array.diff/ArrayDiff.jav
argglobal
%argdel
$argadd arrayDiff.c
edit ~/Documents/Code-Wars/Array.diff/arrayDiff.c
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
wincmd _ | wincmd |
split
wincmd _ | wincmd |
split
2wincmd k
wincmd w
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 24 + 26) / 52)
exe 'vert 1resize ' . ((&columns * 118 + 118) / 236)
exe '2resize ' . ((&lines * 25 + 26) / 52)
exe 'vert 2resize ' . ((&columns * 118 + 118) / 236)
exe '3resize ' . ((&lines * 16 + 26) / 52)
exe 'vert 3resize ' . ((&columns * 117 + 118) / 236)
exe '4resize ' . ((&lines * 16 + 26) / 52)
exe 'vert 4resize ' . ((&columns * 117 + 118) / 236)
exe '5resize ' . ((&lines * 16 + 26) / 52)
exe 'vert 5resize ' . ((&columns * 117 + 118) / 236)
argglobal
setlocal fdm=syntax
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=1
setlocal fml=1
setlocal fdn=20
setlocal fen
7
normal! zo
11
normal! zo
13
normal! zo
16
normal! zo
let s:l = 10 - ((8 * winheight(0) + 12) / 24)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 10
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/Code-Wars/Array.diff/ArrayDiff.jav", ":p")) | buffer ~/Documents/Code-Wars/Array.diff/ArrayDiff.jav | else | edit ~/Documents/Code-Wars/Array.diff/ArrayDiff.jav | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/Code-Wars/Array.diff/ArrayDiff.jav
endif
balt ~/Documents/Code-Wars/Array.diff/arrayDiff.c
setlocal fdm=syntax
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=2
setlocal fml=1
setlocal fdn=20
setlocal fen
1
normal! zo
let s:l = 1 - ((0 * winheight(0) + 12) / 25)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 018|
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/Code-Wars/Array.diff/arrayDiff.hs", ":p")) | buffer ~/Documents/Code-Wars/Array.diff/arrayDiff.hs | else | edit ~/Documents/Code-Wars/Array.diff/arrayDiff.hs | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/Code-Wars/Array.diff/arrayDiff.hs
endif
balt ~/Documents/Code-Wars/Array.diff/arrayDiff.c
setlocal fdm=syntax
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 3 - ((2 * winheight(0) + 8) / 16)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 3
normal! 043|
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/Code-Wars/Array.diff/arrayDiff.py", ":p")) | buffer ~/Documents/Code-Wars/Array.diff/arrayDiff.py | else | edit ~/Documents/Code-Wars/Array.diff/arrayDiff.py | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/Code-Wars/Array.diff/arrayDiff.py
endif
balt ~/Documents/Code-Wars/Array.diff/arrayDiff.c
setlocal fdm=syntax
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 2 - ((1 * winheight(0) + 8) / 16)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 2
normal! 039|
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/Code-Wars/Array.diff/arrayDiff.rs", ":p")) | buffer ~/Documents/Code-Wars/Array.diff/arrayDiff.rs | else | edit ~/Documents/Code-Wars/Array.diff/arrayDiff.rs | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/Code-Wars/Array.diff/arrayDiff.rs
endif
balt ~/Documents/Code-Wars/Array.diff/arrayDiff.c
setlocal fdm=syntax
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=1
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 3 - ((2 * winheight(0) + 8) / 16)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 3
normal! 0
wincmd w
2wincmd w
exe '1resize ' . ((&lines * 24 + 26) / 52)
exe 'vert 1resize ' . ((&columns * 118 + 118) / 236)
exe '2resize ' . ((&lines * 25 + 26) / 52)
exe 'vert 2resize ' . ((&columns * 118 + 118) / 236)
exe '3resize ' . ((&lines * 16 + 26) / 52)
exe 'vert 3resize ' . ((&columns * 117 + 118) / 236)
exe '4resize ' . ((&lines * 16 + 26) / 52)
exe 'vert 4resize ' . ((&columns * 117 + 118) / 236)
exe '5resize ' . ((&lines * 16 + 26) / 52)
exe 'vert 5resize ' . ((&columns * 117 + 118) / 236)
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
