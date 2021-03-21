base=$(pwd)
mkdir unit_test_two
mkdir unit_test_three
mkdir unit_test_four
mkdir unit_test_five
cp libft/refazer.sh .
cp libft/teste1.txt .
cp libft/teste2.txt .
cp libft/teste3.txt .
git clone https://github.com/jtoty/Libftest
git clone https://github.com/alelievr/libft-unit-test unit_test_two/libft-unit-test
git clone https://github.com/ska42/libft-war-machine unit_test_three/libft-war-machine
git clone https://github.com/t0mm4rx/libftdestructor unit_test_four/libftdestructor
git clone https://github.com/Tripouille/libftTester unit_test_five/libftTester
bose=$(echo $base | sed 's/\//\\\//g')
echo "base = \"$base\""
echo "bose = \"$bose\""
cat refazer.sh | sed "s/base=.*$/base=$bose/g" > oxi
mv oxi refazer.sh
chmod 775 refazer.sh
cp -r -v -n unit_test_two/libft-unit-test unit_test_two/clone
cp -r -v -n unit_test_three/libft-war-machine unit_test_three/clone
cp -r -v -n unit_test_four/libftdestructor unit_test_four/clone
cp -r -v -n unit_test_five/libftTester unit_test_five/clone
