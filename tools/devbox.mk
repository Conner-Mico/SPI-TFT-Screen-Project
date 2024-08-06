ifndef DEVBOX_INCLUDED
DEVBOX_INCLUDED = 1
endif

.PHONY: get-devbox
get-devbox:
	curl -fsSL https://get.jetify.com/devbox | bash

.PHONY: shell
shell:
	devbox shell
