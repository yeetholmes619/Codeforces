s = input()
o = "g++ -std=c++17 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment " +s+ ".cpp -o " + s
print(o)
