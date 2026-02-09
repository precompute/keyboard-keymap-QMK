;;; Directory Local Variables            -*- no-byte-compile: t -*-
;;; For more information see (info "(emacs) Directory Variables")

((c-mode . ((eval . (outline-minor-mode 1))
            (outline-regexp . "^/\\* \\(\\*+\\)")
            (outline-level . (lambda () (- (match-end 1) (match-beginning 1))))
            (outline-search-function . nil))))
