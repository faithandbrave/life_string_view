find tests/ example/ -iname '*.h' -o -iname '*.cpp' | xargs clang-format -style=file -i
