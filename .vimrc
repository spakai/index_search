set exrc
set secure
set tabstop=4        " tab width is 4 spaces
set shiftwidth=4     " indent also with 4 spaces
set expandtab        " expand tabs to spaces
set colorcolumn=110
highlight ColorColumn ctermbg=darkgray
set makeprg=make\ -C\ build\ -j9
nnoremap <F4> :make!<cr>
nnoremap <F5> :!cd build && ./test<cr>
