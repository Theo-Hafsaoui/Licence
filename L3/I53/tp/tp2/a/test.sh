set -e
# prend une expression arithmétique en argument
# renvoie la liste de tokens, et la compile
# exécute ensuite bc avec l'expression, puis a.out
echo "import Scanner; print(Scanner.scanner('$@'))" | python
python compilo.py <(echo "$@")
printf "\e[38;2;220;213;121m"
cat a.out
printf "\e[0m"
echo "bc: $(bc <<< "$@")"
echo "a.out: $(python a.out)"
