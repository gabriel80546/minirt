# git clone https://github.com/mrjvs/42cursus_gnl_tests
caminho=$(pwd)
mkdir testeum
git clone https://github.com/mrjvs/42cursus_gnl_tests testeum/repo
chmod 775 testeum/repo/*.sh
cp -r -v -n testeum/repo testeum/copia
#echo $caminho
caminho=$(echo $caminho | sed 's/\//\\\//g')
#echo $caminho
cp gnl/refazer.sh .
cp gnl/cmd .
cat refazer.sh | sed "s/fWU3KdermTW3n9FRbtXwZ7AM/$caminho/g" > temp
mv temp refazer.sh
