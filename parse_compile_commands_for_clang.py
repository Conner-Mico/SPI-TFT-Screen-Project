#! /bin/python3
import sys
import re

transforms = { 
    ('/usr/bin/arm-none-eabi-gcc', '/usr/lib/llvm-19/bin/clang'),
    # for devbox
    ('/nix/store/.*/arm-none-eabi-gcc', 'clang'),
    ('-mcpu=.*? ', ''),
    ('-mfloat-abi=.*? ', ''),
    ('-mfpu=.*? ', ''),
    ('-fdump-ipa-cgraph','')
}

def regexLine(line:str) -> str:
    for transform in transforms:
        line = re.sub(transform[0], transform[1], line)
        
    return line

def main(filepath):
    with open(filepath, 'r') as f, open(filepath+".mod", 'w') as w:
        lines = f.readlines()
        for line in lines:
            w.write(regexLine(line))



if __name__ == "__main__":
    try:
        main(sys.argv[1])
    except:
        main("./build_debug/compile_commands.json")

    
