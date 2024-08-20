SHELL := /bin/bash
# you can set this to 1 to see all commands that are being run
VERBOSE ?= 0

.DEFAULT_GOAL := build

# Define document locations
MD_DOCS := $(shell find ./docs -name "*.md")
PUML_DOCS := $(shell find ./docs -name "*.puml")
DRAWIO_DOCS := $(shell find ./docs -name "*.drawio")

include tools/devbox.mk

.PHONY: build
build:
	cmake --build build_debug

.PHONY: removebuild
removebuild:
	rm -rf build_debug

.PHONY: generate-trice
generate-trice: removebuild
	cmake -G Ninja -B build_debug -DTRICE_GLOBAL_ON=ON

.PHONY: generate-no-trice
generate-no-trice: removebuild
	cmake -G Ninja -B build_debug -DTRICE_GLOBAL_ON=OFF

.PHONY: build-debug
build-debug: build

.PHONY: build-release
build-release:
	cmake --build build_release

.PHONY: test
test:
	ceedling test:all

.PHONY: clean
clean: clean-build clean-test

.PHONY: clean-debug
clean-debug: clean-debug-build clean-test

.PHONY: clean-release
clean-release: clean-release-build clean-test

.PHONY: clean-build
clean-build:
	cmake --build build_debug --target clean

.PHONY: clean-debug-build
clean-debug-build: clean-build
	cmake --build build_debug --target clean

.PHONY: clean-release-build
clean-release-build:
	cmake --build build_release --target clean

clean-test:
	ceedling clean

.PHONY: rebuild
rebuild: clean-debug-build build-debug

.PHONY: rebuild-debug
rebuild-debug: rebuild

.PHONY: rebuild-release
rebuild-debug: clean-release-build build-release

.PHONY: regenerate
regenerate: remove-debug-build generate-debug build-debug

.PHONY: regenerate-debug
regenerate-debug: regenerate

.PHONY: regenerate-release
regenerate-release: remove-release-build generate-release build-release

.PHONY: generate
generate:
	cmake -G Ninja -B build_debug

.PHONY: generate-debug
generate-debug: generate

.PHONY: generate-release
generate-release:
	cmake -G Ninja -B build_release -DBUILD_RELEASE=ON

.PHONY: remove-debug-build
remove-debug-build:
	rm -rf build_debug/**

.PHONY: remove-release-build
remove-release-build:
	rm -rf build_release/**

.PHONY: mmg
mmg:
	python3 knowledge_base/tools/generate_memory_map.py --linker ld/memory_map/memory_map.ld --header ld/memory_map/memory_map.h --python ld/memory_map/memory_map.py

.PHONY: format-check
format-check: have-clang-19
	git ls-files -- 'src/**' | grep -E '\.(c|h)$$' | xargs clang-format-19 --style=file:knowledge_base/coding/.clang-format -n --Werror
	git ls-files | grep -E "(CMake|\.cmake)" | xargs cmake-format --check

.PHONY: git-is-clean
git-is-clean:
	@git diff --quiet --exit-code || (echo "There are unstaged changes, it is not safe to run this command"; exit 1)

.PHONY: format-all
format-all: have-clang-19 git-is-clean
	@git ls-files -- 'src/**' | grep -E '\.(c|h)$$' | xargs clang-format-19 --style=file:./.clang-format -i
	@git ls-files | grep -E '(CMake|\.cmake)' | xargs cmake-format -i
	@echo "If happy with the changes you can amend your last commit with git commit -a --amend --no-edit to apply changes without an new commit"

.PHONY: have-clang-19
have-clang-19:
	@which clang-format-19 &> /dev/null || (echo "Missing clang-format 'sudo make get-clang'"; exit 1)
	@which clang-tidy-19 &> /dev/null || (echo "Missing clang-tidy 'sudo make get-clang'"; exit 1)

.PHONY: get-clang
get-clang:
	wget https://apt.llvm.org/llvm.sh
	chmod +x llvm.sh
	./llvm.sh 19
	apt install clang-format-19 clang-tidy-19
	rm llvm.sh

.PHONY: flash
flash: build
	cmake --build build_debug --target flash

#Works like flash, but to a specific serial number on JTAG. (For now, it is just
#set to Garet's HIL locator, but will allow you to input serial number in future)
.PHONY: flashSerial
flashSerial: build
	cmake --build build_debug --target flashSerial

# This target is like flash, but stops execution at program start
.PHONY: debug
debug: build
	cmake --build build_debug --target debug

.PHONY: tools
tools:
	@echo "Downloading tools..."
	apt-get update
	apt-get -y install make cmake gcc-arm-none-eabi binutils-arm-none-eabi build-essential ruby ccache ninja-build
	make -C knowledge_base tools
	gem install ceedling

.PHONY: json-clean
json-clean:
	git restore li.json til.json

.PHONY: trice-launch
trice-launch:
	./debug/start_rtt.sh

.PHONY: trice-attach
trice-attach:
	./debug/start_rtt_attach.sh

.PHONY: git-hooks
git-hooks:
	git config --local core.hooksPath .githooks/
.PHONY: git-clean
git-clean:
	git clean -d -f

.PHONY: clang-tidy
clang-tidy:
	./knowledge_base/scripts/parse_compile_commands_for_clang.py ./build_debug/compile_commands.json
	mv ./build_debug/compile_commands.json.mod ./build_debug/compile_commands.json
	set -o pipefail && /usr/lib/llvm-19/bin/run-clang-tidy -j `nproc --all` -use-color -extra-arg=-Wno-implicit-function-declaration -config-file ./knowledge_base/.clang-tidy -p build_debug -source-filter `pwd`/src/ -header-filter `pwd`/src/ 2>/dev/null | grep -v clang-tidy

.PHONY: clang-tidy-fix
clang-tidy-fix: git-is-clean
	./knowledge_base/scripts/parse_compile_commands_for_clang.py ./build_debug/compile_commands.json
	mv ./build_debug/compile_commands.json.mod ./build_debug/compile_commands.json
	/usr/lib/llvm-19/bin/run-clang-tidy -j `nproc --all` -fix -use-color -extra-arg=-Wno-implicit-function-declaration -config-file ./knowledge_base/.clang-tidy -p build_debug -source-filter `pwd`/src/ -header-filter `pwd`/src/ 2>/dev/null
	@echo "If happy with the changes you can ammend your last commit with git commit --ammend --no-edit to apply changes without a new commit"
